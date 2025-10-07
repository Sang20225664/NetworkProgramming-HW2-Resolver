#include "validation.h"
#include <arpa/inet.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Check if a string is a valid IPv4 address using inet_pton.
 * @param ip The string to check (e.g., "192.168.1.1")
 * @return true if valid IPv4, false otherwise
 */

bool isValidIPv4(const char *ip)
{
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr));
}

/*
 * @brief Check if a string is an incomplete IPv4 address.
 * @param ip The string to check (e.g., "192.168.1")
 * @return true if incomplete IPv4, false otherwise
 */
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
