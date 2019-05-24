#include "../list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct list_el {
    int _;
    LIST_EL_STRUCT(struct list_el);
};

typedef LIST_TYPE(struct list_el) list_t;

int main(void) {
    list_t list = NEW_LIST();

    assert(LIST_FIRST(list) == NULL);
    assert(LIST_LAST(list) == NULL);

    /* ---- */

    struct list_el *e2 = calloc(1, sizeof(struct list_el));
    e2->_ = 2;

    LIST_INSERT_FIRST(list, e2);

    assert(LIST_FIRST(list) == e2);
    assert(LIST_LAST(list) == e2);

    assert(LIST_PREV(e2) == NULL);
    assert(LIST_NEXT(e2) == NULL);

    /* ---- */

    struct list_el *e1 = calloc(1, sizeof(struct list_el));
    e1->_ = 1;

    LIST_INSERT_FIRST(list, e1);

    assert(LIST_FIRST(list) == e1);
    assert(LIST_LAST(list) == e2);

    assert(LIST_PREV(e1) == NULL);
    assert(LIST_NEXT(e1) == e2);
    assert(LIST_PREV(e2) == e1);
    assert(LIST_NEXT(e2) == NULL);

    /* ---- */

    struct list_el *e4 = calloc(1, sizeof(struct list_el));
    e4->_ = 4;

    LIST_INSERT_LAST(list, e4);

    assert(LIST_FIRST(list) == e1);
    assert(LIST_LAST(list) == e4);

    assert(LIST_PREV(e1) == NULL);
    assert(LIST_NEXT(e1) == e2);
    assert(LIST_PREV(e2) == e1);
    assert(LIST_NEXT(e2) == e4);
    assert(LIST_PREV(e4) == e2);
    assert(LIST_NEXT(e4) == NULL);

    /* ---- */

    struct list_el *e3 = calloc(1, sizeof(struct list_el));
    e3->_ = 3;

    LIST_INSERT_AFTER(list, e2, e3);

    assert(LIST_FIRST(list) == e1);
    assert(LIST_LAST(list) == e4);

    assert(LIST_PREV(e1) == NULL);
    assert(LIST_NEXT(e1) == e2);
    assert(LIST_PREV(e2) == e1);
    assert(LIST_NEXT(e2) == e3);
    assert(LIST_PREV(e3) == e2);
    assert(LIST_NEXT(e3) == e4);
    assert(LIST_PREV(e4) == e3);
    assert(LIST_NEXT(e4) == NULL);

    /* ---- */

    struct list_el *cur = NULL;
    LIST_FOREACH(list, cur) {
        printf("%d\n", cur->_);
    }

    free(e1);
    free(e2);
    free(e3);

    return 0;
}
