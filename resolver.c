#include "resolver.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
Function to check if the input string is a valid IPv4 address.
First checks for NULL input and length constraints.
Then checks the length is between 7 and 15 characters. (0.0.0.0 to 255.255.255.255)
Makes a copy of the input string to avoid modifying the original.
Splits the string by '.' and checks each segment:
- Each segment must be numeric.
- Each segment must be between 0 and 255.
- There must be exactly 3 dots in the input string.
Returns true if valid, false otherwise.
*/

bool isValidIPv4(const char *ip)
{
    if (ip == NULL)
        return false;

    int len = strlen(ip);
    if (len < 7 || len > 15)
        return false;

    char temp[16];
    strcpy(temp, ip);

    int num, dots = 0;
    char *ptr = strtok(temp, ".");

    if (ptr == NULL)
        return false;

    while (ptr)
    {
        if (!isdigit(*ptr))
            return false;

        num = atoi(ptr);
        if (num < 0 || num > 255)
            return false;

        ptr = strtok(NULL, ".");
        if (ptr != NULL)
            dots++;
    }

    return dots == 3;
}