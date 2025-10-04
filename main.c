#include <stdio.h>
#include <stdlib.h>
#include "resolver.h"

/*
Main function will check for correct number of arguments
If the number of arguments is incorrect, it will print a usage message and exit.
Else it will proceed with the provided argument.

*/
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
        printf("Input is a valid IPv4 address: %s\n", input);
    }
    else
    {
        printf("Input is a domain name: %s\n", input);
    }
}
