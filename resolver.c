#include "resolver.h"
#include "validation/validation.h"
#include "dns_resolution/dns_resolution.h"
#include "ip_resolution/ip_resolution.h"
#include <stdio.h>

/**
 * @brief Handle the resolution of a domain or IP address.
 * @param input The domain or IP address to resolve.
 * - If input is a valid IPv4 address, calls resolveIP.
 * - If input is an incomplete IPv4 address, prints "Not found information".
 * - Otherwise, treats input as a domain and calls resolveDomain.
 */
void handleResolution(const char *input)
{
    if (isValidIPv4(input))
        resolveIP(input);

    else if (isIncompleteIPv4(input))
        printf("Not found information\n");
    else
        resolveDomain(input);
}
