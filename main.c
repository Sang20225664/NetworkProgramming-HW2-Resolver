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
        printf("Valid IPv4: %s (will resolve later)\n", input);
    }
    else
    {
        resolveDomain(input);
    }

    return 0;
}
