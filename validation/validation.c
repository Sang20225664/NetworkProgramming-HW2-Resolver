#include "validation.h"
#include <arpa/inet.h>

/**
 * @brief Check if a string is a valid IPv4 address.
 */

bool isValidIPv4(const char *ip)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));

    if (result != 1)
        return false;
    int dotCount = 0;
    for (int i = 0; ip[i] != '\0'; i++)
    {
        if (ip[i] == '.')
        {
            dotCount++;
        }
    }
    return dotCount == 3;
}
