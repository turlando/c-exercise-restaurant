#ifndef __RESTAURANT_TIMETABLE__
#define __RESTAURANT_TIMETABLE__

#include <stdbool.h>

/* Number of days in a month + padding element. */
#define TIMETABLE_LENGTH (31 + 1)

#define TIMETABLE_HOURS_IN_DAY 24U
#define TIMETABLE_DAY_CLOSED   0U

/* This data structure represents the opening schedule
 * of the restaurant.
 *
 * To avoid to manually manage the memory allocation we're
 * using a struct with a single data field which is the
 * actual data structure.
 *
 * The first element (indexed by zero) is just a padding
 * item that allows us to index the first day of the month
 * by accessing to the element indexed by 1 in the array.
 */
struct timetable {
    unsigned int _[TIMETABLE_LENGTH];
};

struct timetable timetable_read_file(const char *filename);
bool timetable_is_open_day(struct timetable timetable, unsigned int day);
bool timetable_is_open_hour(struct timetable timetable,
                            unsigned int day, unsigned int hour);

#endif /* __RESTAURANT_TIMETABLE__ */
