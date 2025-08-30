/* netmap naive
 * Minimal IPv4 TCP connect() scanner (educational use).
 */

#include "nm-naive.h"

int16    port;             /* target TCP port */
in_addr_t current, ending; /* scan range [current..ending] */

/* Generate next IPv4 address (stdin if no range, else ++current). */
in_addr_t generate(void) {
    int8 *p;
    int8 buf[16];
    int32 size;

    /* No range → read one IP from stdin */
    if ((!current) && (!ending)) {
        memset(buf, 0, sizeof buf);
        if (!fgets((char *)buf, 15, stdin))
            return (in_addr_t)0;

        size = (int)strlen((char *)buf);
        if (size < 7)                 /* too short to be a valid IPv4 */
            return (in_addr_t)0;

        /* Trim trailing newline/CR */
        p = (int8 *)buf + (size - 1);
        if ((*p == '\n') || (*p == '\r'))
            *p = 0;

        return inet_addr((char *)buf);
    }

    /* Range mode */
    if (current >= ending)
        return (in_addr_t)0;          /* finished */

    current++;                        /* next address */
    return current;
}

/* Try TCP connect() to ip:port; on success, print banner. */
bool tcpconnect(in_addr_t ip, int16 port) {
    struct sockaddr_in sock;
    int s, ret;

    s = socket(AF_INET, SOCK_STREAM, 0);
    assert(s >= 0);

    sock.sin_family      = AF_INET;
    sock.sin_port        = htons((int)port);
    sock.sin_addr.s_addr = ip;

    ret = connect(s, (struct sockaddr *)&sock, sizeof sock);

    if (ret) {
        close(s);
        return false;
    }

    header(s, ip);
    close(s);
    return true;
}

/* Read up to 255 bytes and print "IP: banner" (or IP if none). */
int8 *header(int s, in_addr_t ip) {
    ssize_t i;
    int8 *p;
    static int8 buff[256];

    memset(buff, 0, sizeof buff);
    i = read(s, (char *)buff, 255);

    if (i <= 0) {
        printf("0x%x\n", ip);
        return buff;
    }

    /* Strip one trailing newline/CR if present */
    p = (int8 *)buff + (i - 1);
    if ((*p == '\n') || (*p == '\r'))
        *p = 0;

    printf("0x%x: %s\n", ip, buff);
    return buff;
}

/* Usage: ./nm-naive <port> [start_ip] [end_ip] */
int main(int argc, char **argv) {
    in_addr_t ip;

    if (argc < 2) {
        fprintf(stderr,
                "Usage: %s <port> [start ip addr] [end ip addr]\n",
                *argv);
        return -1;
    }

    /* Optional IP range */
    if (argc > 2) {
        current = inet_addr(argv[2]);
        ending  = (argc > 3) ? inet_addr(argv[3])
                             : inet_addr("223.255.254.255");

        if ((current == INADDR_NONE) ||
            (ending  == INADDR_NONE) ||
            (ending  <  current)) {
            fprintf(stderr,
                    "Usage: %s <port> [start ip addr] [end ip addr]\n",
                    *argv);
            return -1;
        }
    }

    port = (int16)atoi(argv[1]);

    while ((ip = generate())) {
        (void)tcpconnect(ip, port);
    }

    return 0;
}
