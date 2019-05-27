#ifndef __RESTAURANT_ROOM__
#define __RESTAURANT_ROOM__

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
    {'A', PIZZERIA,   2U, {{4U},      /* 0.0 */
                           {5U}}},    /* 0.1 */
    {'B', PIZZERIA,   1U, {{4U}}},    /* 1.0 */
    {'C', RESTAURANT, 1U, {{8U}}},    /* 2.0 */
    {'D', RESTAURANT, 3U, {{4U},      /* 3.0 */
                           {3U},      /* 3.1 */
                           {3U}}},    /* 3.2 */
    {'E', RESTAURANT, 4U, {{4U},      /* 4.0 */
                           {4U},      /* 4.1 */
                           {4U},      /* 4.2 */
                           {2U}}}     /* 4.3 */
};

#endif /* __RESTAURANT_ROOM__ */
