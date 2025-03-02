#include "netmap.h"

in_addr_t generate(void);
int8 *header(int, in_addr_t);
int main(int, char**);
bool tcpconnect(in_addr_t, int16);
