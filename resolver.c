#include "resolver.h"
#include <arpa/inet.h>
#include <netinet/in.h>

/**
 * @brief Check if a string is a valid IPv4 address.
 */
bool isValidIPv4(const char *ip)
{
    struct sockaddr_in sa;
    // inet_pton: parse string to binary form
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    return result == 1; // 1 = valid, 0 = invalid, -1 = error
}
