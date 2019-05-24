#include "../list.h"
#include <stdio.h>
#include <stdlib.h>

struct list_el {
    int _;
    LIST_EL_STRUCT(struct list_el);
};

typedef LIST_TYPE(struct list_el) list_t;

int main(void) {
    list_t list = NEW_LIST();

    struct list_el *e1 = calloc(1, sizeof(struct list_el));
    e1->_ = 1;

    struct list_el *e2 = calloc(1, sizeof(struct list_el));
    e2->_ = 2;

    LIST_INSERT_FIRST(list, e2);
    LIST_INSERT_FIRST(list, e1);

    struct list_el *cur = NULL;
    LIST_FOREACH(list, cur) {
        printf("%d\n", cur->_);
    }

    free(e1);
    free(e2);

    return 0;
}
