#ifndef __RESTAURANT_TIMETABLE__
#define __RESTAURANT_TIMETABLE__

/* Number of days in a month + padding element. */
#define TIMETABLE_LENGTH (31 + 1)

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

#endif /* __RESTAURANT_TIMETABLE__ */
