#include "../list.h"

NEW_LIST_TYPE(int_list_t, int);

int main(void) {
    LIST_NAME(int_list_t) list = NEW_LIST();

    LIST_EL_NAME(int_list_t) *e1 = NEW_LIST_EL(int_list_t, 1);
    LIST_EL_NAME(int_list_t) *e2 = NEW_LIST_EL(int_list_t, 2);
    LIST_EL_NAME(int_list_t) *e3 = NEW_LIST_EL(int_list_t, 3);

    return 0;
}
