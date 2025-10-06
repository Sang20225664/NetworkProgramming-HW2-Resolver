#include "validation.h"
#include <arpa/inet.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Check if a string is a valid IPv4 address.
 */

bool isValidIPv4(const char *ip)
{
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr));
}

bool isIncompleteIPv4(const char *ip)
{
    int dotCount = 0;
    bool hasDigit = false;
    for (int i = 0; ip[i] != '\0'; i++)
    {
        if (ip[i] == '.')
        {
            dotCount++;
        }
        else if (isdigit(ip[i]))
        {
            hasDigit = true;
        }
    }
    return dotCount < 3 && hasDigit;
}
