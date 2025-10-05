#ifndef RESOLVER_H
#define RESOLVER_H

#include <stdbool.h>

bool isValidIPv4(const char *ip);
void resolveDomain(const char *domain); // Thêm khai báo này
void resolveIP(const char *ip);
void handleResolution(const char *input);

#endif