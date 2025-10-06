#include <stdio.h>
#include "resolver.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <domain-or-ip>\n", argv[0]);
        return 1;
    }
    

    handleResolution(argv[1]);

    return 0;
}
