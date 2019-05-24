#ifndef __RESTAURANT_LIST__
#define __RESTAURANT_LIST__

#include <stddef.h>  /* Provides size_t */
#include <stdlib.h>  /* Provides calloc */

#define _LIST_EL_META_FIELD __list_el_meta

#define LIST_EL_STRUCT(type)     \
    struct _LIST_EL_META_FIELD { \
        type *prev;              \
        type *next;              \
    } _LIST_EL_META_FIELD

#define LIST_TYPE(type) \
    struct {            \
        size_t count;   \
        type *head;     \
        type *tail;     \
    }

#define NEW_LIST() \
    {0, NULL, NULL}

#define LIST_FIRST(l) \
    (l.head)

#define LIST_NEXT(e) \
    (e->_LIST_EL_META_FIELD.next)

#define LIST_PREV(e) \
    (e->_LIST_EL_META_FIELD.prev)

#define LIST_INSERT_FIRST(l, e)                      \
    do {                                             \
        LIST_NEXT(e) = LIST_FIRST(l);                \
        if (LIST_FIRST(l) != NULL)                   \
            LIST_PREV(LIST_FIRST(l)) = LIST_NEXT(e); \
        LIST_FIRST(l) = e;                           \
    } while(0)                                       \


#define	LIST_FOREACH(l, e)    \
    for ((e) = LIST_FIRST(l); \
         (e);                 \
         (e) = LIST_NEXT(e))

#endif /* __RESTAURANT_LIST__ */
