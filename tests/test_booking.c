#include "../booking.h"
#include <stdio.h>

#define BOOKING_FILE "test_booking.txt"

void print_record(struct booking record) {
    printf("day:          %02d\n", record.day);
    printf("hour:         %02d\n", record.hour);
    printf("room_type:    %c\n", (record.room_type == RESTAURANT) ? 'R' : 'P');
    printf("name:         %s\n", record.name);
    printf("people_count: %02d\n", record.people_count);
    printf("---\n");
}

int main(void) {
    booking_list_t list = booking_read_file(BOOKING_FILE);

    printf("---\n");

    struct booking_list_el *el = NULL;
    LIST_FOREACH(list, el) {
        print_record(el->_);
    }

    return 0;
}
