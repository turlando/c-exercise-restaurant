#ifndef __RESTAURANT_ROOM__
#define __RESTAURANT_ROOM__

#define ROOM_MAX_TABLES 16

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
    struct table tables[ROOM_MAX_TABLES];
};

static const struct room rooms[] = {
    {'A', PIZZERIA,   2U, {{4U}, {5U}}},
    {'B', PIZZERIA,   2U, {{4U}, {4U}}},
    {'C', RESTAURANT, 1U, {{8U}}},
    {'D', RESTAURANT, 3U, {{4U}, {3U}, {3U}}},
    {'E', RESTAURANT, 4U, {{4U}, {4U}, {4U}, {2U}}}
};

#endif /* __RESTAURANT_ROOM__ */
