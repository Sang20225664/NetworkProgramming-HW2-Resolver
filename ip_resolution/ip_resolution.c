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
    char host[NI_MAXHOST];
    int result;

    sa.sin_family = AF_INET;

    if (inet_pton(AF_INET, ip, &sa.sin_addr) != 1)
    {
        printf("Not found information\n");
        return;
    }
    result = getnameinfo((struct sockaddr *)&sa, sizeof(sa), host, sizeof(host), NULL, 0, NI_NAMEREQD);
    if (result != 0)
    {
        printf("Not found information\n");
        return;
    }

    printf("%s\n", host);
}