#ifndef RESOLVER_H
#define RESOLVER_H

#include <stdbool.h>

// Check if input string is a valid IPv4 address
bool isValidIPv4(const char *ip);

void resolveDomain(const char *domain);

void resolveIP(const char *ip);

#endif
