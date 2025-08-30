#include "netmap.h"

/* Generate next IPv4 address to scan (from stdin or range). */
in_addr_t generate(void);

/* Read and print banner/response from socket for given IP. */
int8 *header(int s, in_addr_t ip);

/* Program entry point: parse args, set range, run scan. */
int main(int argc, char **argv);

/* Try TCP connect() to ip:port, print banner if successful. */
bool tcpconnect(in_addr_t ip, int16 port);

static inline void zero(void *p, size_t n) { memset(p, 0, n); }
