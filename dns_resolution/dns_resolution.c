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
 * Use AI_ADDRCONFIG to avoid returning addresses that are not configured on the local system.
 * Prints all resolved IP addresses.
 */
void resolveDomain(const char *domain)
{
    struct hostent *he;
    struct in_addr addr;
    char ipstr[INET_ADDRSTRLEN];

    // gethostbyname() nghiêm ngặt hơn với input
    he = gethostbyname(domain);

    if (he == NULL)
    {
        printf("Not found information\n");
        return;
    }

    // Print all IP addresses
    for (int i = 0; he->h_addr_list[i] != NULL; i++)
    {
        addr.s_addr = *((unsigned long *)he->h_addr_list[i]);
        inet_ntop(AF_INET, &addr, ipstr, sizeof(ipstr));
        printf("%s\n", ipstr);
    }
}