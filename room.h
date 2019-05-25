#ifndef __RESTAURANT_ROOM__
#define __RESTAURANT_ROOM__

#include <stdbool.h>

#define ROOM_COUNT      5
#define ROOM_MAX_TABLES 16

#define ROOM_TABLES_AVAILABILITY_SIZE (sizeof(unsigned int) * ROOM_COUNT)

enum room_id {
    ROOM_A = 0,
    ROOM_B = 1,
    ROOM_C = 2,
    ROOM_D = 3,
    ROOM_E = 4,
};

enum room_type {
    RESTAURANT = (1 << 1),
    PIZZERIA   = (1 << 2),
};

/* This structure could just be a simple integer,
 * but it is wrapped inside a struct so that adding
 * more fields is easier.
 */
struct table {
    unsigned int id;
    unsigned int seats;
};

struct room {
    const char name;
    const enum room_type type;
    const unsigned int tables_count;
    const struct table tables[ROOM_MAX_TABLES];
};

struct room_tables_availability {
    unsigned int _[ROOM_COUNT];
};

static const struct room rooms[ROOM_COUNT] = {
    {'A', PIZZERIA,   2U, {{1U << 1, 4U},      /* 00 */
                           {1U << 2, 5U}}},
    {'B', PIZZERIA,   1U, {{1U << 1, 4U}}},    /* 01 */
    {'C', RESTAURANT, 1U, {{1U << 1, 8U}}},    /* 02 */
    {'D', RESTAURANT, 3U, {{1U << 1, 4U},      /* 03 */
                           {1U << 2, 3U},
                           {1U << 3, 3U}}},
    {'E', RESTAURANT, 4U, {{1U << 1, 4U},      /* 04 */
                           {1U << 2, 4U},
                           {1U << 3, 4U},
                           {1U << 4, 2U}}}
};

#endif /* __RESTAURANT_ROOM__ */
