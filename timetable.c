#include "timetable.h"
#include <stdio.h>    /* Provides FILE, fopen,fgets */
#include <string.h>   /* Provides memset */
#include "bitmask.h"  /* Provides MASK_RANGE */
#include "utils.h"    /* Provides FATAL, SKIP_SPACES, TWO_DIGITS_TO_UINT */

#define TIMETABLE_SIZE (sizeof(unsigned int) * TIMETABLE_LENGTH)

#define LINE_BUFFER_LENGTH 128

struct timetable_entry {
    unsigned int day;
    unsigned int hours;
};

static struct timetable_entry parse_entry(const char *s) {
    struct timetable_entry entry = {0U, 0U};

    /* We assume that the first two characters always represent
     * the day of the month.
     */
    entry.day = TWO_DIGITS_TO_UINT(s[0], s[1]);

    /* Move char pointer past two character that we have
     * already parsed.
     */
    s += 2;

    SKIP_SPACES(s);

    /* If we hit a '#' or a '\n' we assume that the day we're
     * parsing is a closing day.
     * entry at this point has the day correctly set and the
     * hours field set to zero wich means closed.
     */
    if (*s == '#' || *s == '\n')
        return entry;

    /* Otherwise we continue parsing the line assuming we hit
     * the opening time for that day.
     */
    unsigned int opening_time = TWO_DIGITS_TO_UINT(s[0], s[1]);

    /* Move char pointer past two character that we have
     * already parsed.
     */
    s += 2;

    SKIP_SPACES(s);

    /* We assume we hit the closing time for that day */
    unsigned int closing_time = TWO_DIGITS_TO_UINT(s[0], s[1]);

    /* In the unsigned in where re're storing the opening hours
     * we flip from 0 to 1 the bits in the interval from 0 to 23
     * representing the opening hours of the restaurant.
     * If the restaurant is open from 19:00 to 22:00 the 19th bit
     * to the 21th bit (included) will be flipped to 1.
     */
    entry.hours = MASK_RANGE(opening_time, closing_time);

    return entry;
}

struct timetable timetable_read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        FATAL("Could not open %s", filename);

    char buffer[LINE_BUFFER_LENGTH];
    struct timetable_entry entry;
    struct timetable timetable;

    /* Initialize timetable to zero */
    memset(timetable._, 0, TIMETABLE_SIZE);

    while (fgets(buffer, LINE_BUFFER_LENGTH, fp) != NULL) {
        /* If the first character is '#' then we skip the whole line. */
        if (buffer[0] == '#')
            continue;

        entry = parse_entry(buffer);

        /* We OR the previous value so that we can have multiple time
         * ranges for a single day with a simple data structure.
         */
        timetable._[entry.day] |= entry.hours;
    }

    return timetable;
}
