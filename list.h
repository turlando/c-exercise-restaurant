#ifndef __RESTAURANT_LIST__
#define __RESTAURANT_LIST__

#include <stddef.h>  /* Provides size_t */
#include <stdlib.h>  /* Provides calloc */

#define LIST_NAME(name) \
    name

#define LIST_EL_NAME(name) \
    name##_el

#define _NEW_LIST_EL_TYPE(name, type)    \
    typedef struct LIST_EL_NAME(name) {  \
        type data;                       \
        struct LIST_EL_NAME(name) *prev; \
        struct LIST_EL_NAME(name) *next; \
    } LIST_EL_NAME(name)

#define _NEW_LIST_TYPE(name)         \
    typedef struct LIST_NAME(name) { \
        size_t count;                \
        LIST_EL_NAME(name) *head;    \
        LIST_EL_NAME(name) *tail;    \
    } LIST_NAME(name)

#define NEW_LIST_TYPE(name, type)  \
    _NEW_LIST_EL_TYPE(name, type); \
    _NEW_LIST_TYPE(name)

#define NEW_LIST() \
    {              \
       0,          \
       NULL,       \
       NULL        \
    }

#define NEW_LIST_EL(name, data) \
    calloc(1, sizeof(name))

#define LIST_LENGHT(list) \
      list.count;

#endif /* __RESTAURANT_LIST__ */
