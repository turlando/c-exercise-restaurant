#ifndef __RESTAURANT_ERROR__
#define __RESTAURANT_ERROR__

#include <stdio.h>   /* Provides vfprintf */
#include <stdlib.h>  /* Provides exit, EXIT_FAILURE */

#define FATAL(fmt, ...)                      \
    do {                                     \
        fprintf(stderr, fmt, ##__VA_ARGS__); \
        exit(EXIT_FAILURE);                  \
    }                                        \
    while(0);

#endif /* __RESTAURANT_ERROR__ */
