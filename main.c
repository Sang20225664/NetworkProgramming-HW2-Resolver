#include <stdio.h>
#include "resolver.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <domain-or-ip>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];

    if (isValidIPv4(input))
    {
        printf("Valid IPv4: %s\n", input);
    }
    else
    {
        printf("Not a valid IPv4, treat as domain: %s\n", input);
    }

    return 0;
}
