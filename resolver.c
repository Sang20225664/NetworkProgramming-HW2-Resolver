#include "resolver.h"
#include "validation/validation.h"
#include "dns_resolution/dns_resolution.h"
#include "ip_resolution/ip_resolution.h"
#include <stdio.h>

void handleResolution(const char *input)
{
    if (isValidIPv4(input))
        resolveIP(input);

    else if (isIncompleteIPv4(input))
        printf("Not found information\n");
    else
        resolveDomain(input);
}
