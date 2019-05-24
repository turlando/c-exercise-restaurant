#ifndef __RESTAURANT_UTILS__
#define __RESTAURANT_UTILS__

#include <stdio.h>   /* Provides vfprintf */
#include <stdlib.h>  /* Provides exit, EXIT_FAILURE */

#define SKIP_SPACES(s) \
    do {               \
    while (*s == ' ')  \
        s += 1;        \
    } while (0)

#define TWO_DIGITS_TO_UINT(c0, c1)   \
    (((c0 - '0') * 10) + (c1 - '0'))

#define FATAL(fmt, ...)                         \
    do {                                        \
        fprintf(stderr, fmt, ##__VA_ARGS__);    \
        exit(EXIT_FAILURE);                     \
    }                                           \
    while(0);

#endif /* __RESTAURANT_UTILS__ */
