#define _GNU_SOURCE
// #define _POSIX_C_SOURCE 200112L
#include "resolver.h"
#include <stdio.h>
#include <string.h> // Cho memset
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stddef.h>
#include <sys/types.h>
#include <netdb.h> // Cho struct addrinfo, getaddrinfo
#include <sys/socket.h>

/**
 * @brief Check if a string is a valid IPv4 address.
 */
bool isValidIPv4(const char *ip)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    return result == 1; // 1 = valid, 0 = invalid, -1 = error
}

void resolveDomain(const char *domain)
{
    struct addrinfo hints, *res, *p;
    char ipstr[INET_ADDRSTRLEN];
    int status;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;       // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP

    if ((status = getaddrinfo(domain, NULL, &hints, &res)) != 0)
    {
        printf("Not found information\n");
        return;
    }

    for (p = res; p != NULL; p = p->ai_next)
    {
        struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
        void *addr = &(ipv4->sin_addr);

        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
        printf("%s\n", ipstr);
    }

    freeaddrinfo(res);
}