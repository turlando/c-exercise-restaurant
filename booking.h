#ifndef __RESTAURANT_BOOKING__
#define __RESTAURANT_BOOKING__

#include "room.h"
#include "list.h"

#define BOOKING_STRING_LENGTH 32

struct booking {
    unsigned int day;
    unsigned int hour;
    enum room_type room_type;
    char name[BOOKING_STRING_LENGTH];
    unsigned int people_count;
};

struct booking_list_el {
    struct booking _;
    LIST_EL_STRUCT(struct booking_list_el);
};

typedef LIST_TYPE(struct booking_list_el) booking_list_t;

booking_list_t booking_read_file(const char *filename);
bool booking_is_possible(booking_list_t bookings, struct booking booking);

#endif /* __RESTAURANT_BOOKING__ */
