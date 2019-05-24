#include "timetable.h"
#include <stdio.h>    /* Provides FILE, fopen */
#include <string.h>   /* Provides memset */
#include "error.h"    /* Provides FATAL */
#include "bitmask.h"  /* Provides MASK_RANGE */

#define LINE_BUFFER_LENGTH 128
#define TIMETABLE_SIZE     (sizeof(unsigned int) * 32)

struct timetable_entry {
    unsigned int day;
    unsigned int hours;
};

static unsigned int two_digits_to_uint(char c0, char c1) {
    unsigned int d0 = c0 - '0';
    unsigned int d1 = c1 - '0';
    return (d0 * 10) + d1;
}

static struct timetable_entry parse_entry(const char *s) {
    struct timetable_entry entry = {0U, 0U};

    /* We assume that the first two characters always represent
     * the day of the month.
     */
    entry.day = two_digits_to_uint(s[0], s[1]);

    /* Move char pointer past two character that we have
     * already parsed.
     */
    s += 2;

    /* Skip spaces */
    while (*s == ' ')
        s += 1;

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
    unsigned int opening_time = two_digits_to_uint(s[0], s[1]);

    /* Move char pointer past two character that we have
     * already parsed.
     */
    s += 2;

    /* Skip spaces */
    while (*s == ' ')
        s += 1;

    /* We assume we hit the closing time for that day */
    unsigned int closing_time = two_digits_to_uint(s[0], s[1]);

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
