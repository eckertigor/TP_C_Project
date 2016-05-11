#include <cstdio>
#include <cstdlib>
#include <cstring>
#ifndef LOG_DEBUG
#define LOG_DEBUG
void realdprintf (int line, const char *func, char const *fmt ...);
#define PDEBUG(...) realdprintf(__LINE__, __FUNCTION__, __VA_ARGS__)
#endif // LOG_DEBUG

