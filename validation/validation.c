#include "validation.h"
#include <arpa/inet.h>

/**
 * @brief Check if a string is a valid IPv4 address.
 */

bool isValidIPv4(const char *ip)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    return result == 1;
}
