#define _GNU_SOURCE // For gethostbyaddr and gethostbyname
// #define _POSIX_C_SOURCE 200112L

#include "../resolver.h"
#include "ip_resolution.h"
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
/**
 * @brief Resolve an IPv4 address to its hostname and aliases.
 * @param ip The IPv4 address to resolve (e.g., "192.168.1.1")
 * @return Prints the hostname and all aliases to stdout, one per line
 *         Prints "Not found information" if IP cannot be resolved
 * Implementation details:
 * - Uses gethostbyaddr() for reverse DNS resolution
 * - Converts the IP address from string to binary format using inet_pton
 */
void resolveIP(const char *ip)
{
    struct in_addr addr;
    struct hostent *he;

    if (inet_pton(AF_INET, ip, &addr) != 1)
    {
        printf("Not found information\n");
        return;
    }

    he = gethostbyaddr(&addr, sizeof(addr), AF_INET);
    if (he == NULL)
    {
        printf("Not found information\n");
        return;
    }

    printf("%s\n", he->h_name);

    for (int i = 0; he->h_aliases[i] != NULL; i++)
    {
        printf("%s\n", he->h_aliases[i]);
    }
}
