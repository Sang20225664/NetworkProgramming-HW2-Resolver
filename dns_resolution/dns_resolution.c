#define _GNU_SOURCE
// #define _POSIX_C_SOURCE 200112L

#include "dns_resolution.h"
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>

/**
 * @brief Resolve a domain name to its IPv4 addresses.
 * @param domain The domain name to resolve (e.g., "google.com")
 * @return Prints all resolved IPv4 addresses to stdout, one per line
 *         Prints "Not found information" if domain cannot be resolved
 *
 * Implementation details:
 * - Uses gethostbyname() for DNS resolution
 * - Iterates through all returned IP addresses
 * - Converts binary addresses to dotted decimal notation
 */
void resolveDomain(const char *domain)
{
    struct hostent *he;
    struct in_addr addr;
    char ipstr[INET_ADDRSTRLEN];

    he = gethostbyname(domain);

    if (he == NULL)
    {
        printf("Not found information\n");
        return;
    }

    for (int i = 0; he->h_addr_list[i] != NULL; i++)
    {
        addr.s_addr = *((unsigned long *)he->h_addr_list[i]);
        inet_ntop(AF_INET, &addr, ipstr, sizeof(ipstr));
        printf("%s\n", ipstr);
    }
}