#ifndef __RESTAURANT_TIMETABLE__
#define __RESTAURANT_TIMETABLE__

/* Just a nast hack to avoid allocating memory dynamically.
 * The first element (indexed by zero) is there just for
 * padding space so that we can refer to the first day of
 * the month as 1 and the last day of the month as 31.
 */
struct timetable {
    unsigned int _[32];
};

struct timetable timetable_read_file(const char *filename);

#endif /* __RESTAURANT_TIMETABLE__ */
