#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200112L

#include "../resolver.h"
#include "ip_resolution.h"
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void resolveIP(const char *ip)
{
    struct sockaddr_in sa;
    char hostname[NI_MAXHOST];

    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;

    if (inet_pton(AF_INET, ip, &sa.sin_addr) != 1)
    {
        printf("Invalid IP address format\n");
        return;
    }

    // Thử resolve với các flag khác nhau
    printf("Reverse DNS lookup for %s:\n", ip);

    // Standard reverse lookup
    if (getnameinfo((struct sockaddr *)&sa, sizeof(sa),
                    hostname, sizeof(hostname), NULL, 0, 0) == 0)
    {
        printf("Hostname: %s\n", hostname);

        // Verify bằng cách resolve lại hostname
        printf("Verification (forward lookup of %s):\n", hostname);
        resolveDomain(hostname);
    }
    else
    {
        printf("Not found information\n");
    }

    // Thử với NI_NAMEREQD flag
    if (getnameinfo((struct sockaddr *)&sa, sizeof(sa),
                    hostname, sizeof(hostname), NULL, 0, NI_NAMEREQD) == 0)
    {
        printf("Canonical name: %s\n", hostname);
    }
}