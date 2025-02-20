/* netmap naive */
#include "netmap.h"

int16 port;
in_addr_t current, ending;

in_addr_t generate(){

    if (current >= ending){
        return (in_addr_t)0;
    }
    else
        current++;
    return current;

}

//INADDR_NONE
int main(int argc, char *argv[]){
    if (argc < 2 ){
        fprintf(stderr,
             "Usage: %s <port> [start ip addr] [end ip addr]\n",
            *argv);
        return -1;
    }

    if (argc > 2){
        current = inet_addr(argv[2]);
        ending = (argc > 3) ?
                inet_addr(argv[3]):
            inet_addr("223.255.254.255");
        
        if ((current == INADDR_NONE) 
        || (ending == INADDR_NONE) 
        || (ending < current)){

            fprintf(stderr,
                "Usage: %s <port> [start ip addr] [end ip addr]\n",
               *argv);

            return -1;
        }
        
    }

    port = (int16)argv[1];
    printf("Port: %d\nStart: %d\nEnd: %d\n", port, current, ending);

    return 0;
}

