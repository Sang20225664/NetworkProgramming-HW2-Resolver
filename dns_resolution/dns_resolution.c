#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200112L

#include "dns_resolution.h"
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>

/**
 * @brief Resolve a domain name to its IPv4 addresses.
 * @param domain The domain name to resolve.
 * Uses getaddrinfo for resolution.
 * Use hints to specify IPv4 and TCP.
 * Use
 * Prints all resolved IP addresses.
 */
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
