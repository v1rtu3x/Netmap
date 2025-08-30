/* netmap.h
 * Shared includes and typedefs for the naive TCP scanner.
 */

#define _GNU_SOURCE

/* Standard C / POSIX headers */
#include <stdio.h>      /* I/O: printf, fprintf */
#include <unistd.h>     /* read, close */
#include <string.h>     /* strlen, memset */
#include <stdlib.h>     /* atoi, malloc, free */
#include <assert.h>     /* assert() */
#include <errno.h>      /* errno codes */
#include <stdbool.h>    /* bool type */

/* Networking */
#include <sys/socket.h> /* socket(), connect() */
#include <netinet/in.h> /* sockaddr_in, htons */
#include <arpa/inet.h>  /* inet_addr, in_addr_t */

/* Simple typedefs for clarity */
typedef unsigned char  int8;   /* 8-bit  */
typedef unsigned short int16;  /* 16-bit */
typedef unsigned int   int32;  /* 32-bit */
