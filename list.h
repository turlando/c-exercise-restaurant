#ifndef __RESTAURANT_LIST__
#define __RESTAURANT_LIST__

#include <stdbool.h> /* Provides bool */
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

#define LIST_IS_EMPTY(l) \
    (l.count == 0 ? true : false)

#define LIST_FIRST(l) \
    (l.head)

#define LIST_LAST(l) \
    (l.tail)

#define LIST_NEXT(e) \
    (e->_LIST_EL_META_FIELD.next)

#define LIST_PREV(e) \
    (e->_LIST_EL_META_FIELD.prev)

#define LIST_INSERT_AFTER(l, p, e)       \
    do {                                 \
        l.count += 1;                    \
        LIST_NEXT(e) = LIST_NEXT(p);     \
        if (LIST_NEXT(p) != NULL)        \
            LIST_PREV(LIST_NEXT(p)) = e; \
        else                             \
            LIST_LAST(l) = e;            \
        LIST_NEXT(p) = e;                \
        LIST_PREV(e) = p;                \
    } while(0)

#define LIST_INSERT_FIRST(l, e)           \
    do {                                  \
        l.count += 1;                     \
        LIST_NEXT(e) = LIST_FIRST(l);     \
        if (LIST_FIRST(l) != NULL)        \
            LIST_PREV(LIST_FIRST(l)) = e; \
        else                              \
            LIST_LAST(l) = e;             \
        LIST_FIRST(l) = e;                \
    } while(0)                            \

#define LIST_INSERT_LAST(l, e)           \
    do {                                 \
        l.count += 1;                    \
        LIST_PREV(e) = LIST_LAST(l);     \
        if (LIST_LAST(l) != NULL)        \
            LIST_NEXT(LIST_LAST(l)) = e; \
        else                             \
            LIST_FIRST(l) = e;           \
        LIST_LAST(l) = e;                \
    } while (0)

#define LIST_REMOVE(l, e)                            \
    do {                                             \
        l.count -= 1;                                \
        if (LIST_NEXT(e) != NULL)                    \
            LIST_PREV(LIST_NEXT(e)) = LIST_PREV(e);  \
        else                                         \
            /* If there is not a next element then   \
             * the previous becomes the new last     \
             * element in the list.                  \
             */                                      \
            LIST_LAST(l) = LIST_PREV(e);             \
        /* If there is not a prev element then the   \
         * previous becomes the new last element     \
         * in the list.                              \
         */                                          \
        if (LIST_PREV(e) == NULL)                    \
            LIST_FIRST(l) = LIST_NEXT(e);            \
        LIST_PREV(e) = LIST_NEXT(e);                 \
    } while (0)

#define	LIST_FOREACH(l, e)    \
    for ((e) = LIST_FIRST(l); \
         (e);                 \
         (e) = LIST_NEXT(e))

#endif /* __RESTAURANT_LIST__ */
