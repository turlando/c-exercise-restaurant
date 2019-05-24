#include "booking.h"
#include <string.h>  /* Provides strncmp, strncpy, strcspn */
#include "error.h"   /* Provides FATAL */
#include "utils.h"   /* Provides SKIP_SPACES, TWO_DIGITS_TO_UINT */

#define RECORD_SYNC_SEQUENCE        "---"
#define RECORD_SYNC_SEQUENCE_LENGTH 3

#define RECORD_FIELD_DAY                 "day"
#define RECORD_FIELD_DAY_LENGTH          3
#define RECORD_FIELD_HOUR                "hour"
#define RECORD_FIELD_HOUR_LENGTH         4
#define RECORD_FIELD_ROOM_TYPE           "room_type"
#define RECORD_FIELD_ROOM_TYPE_LENGTH    9
#define RECORD_FIELD_NAME                "name"
#define RECORD_FIELD_NAME_LENGTH         4
#define RECORD_FIELD_PEOPLE_COUNT        "people_count"
#define RECORD_FIELD_PEOPLE_COUNT_LENGTH 12

#define LINE_BUFFER_LENGTH 128

booking_list_t booking_read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        FATAL("Could not open %s", filename);

    char buffer[LINE_BUFFER_LENGTH];
    struct booking record;
    booking_list_t list = NEW_LIST();

    /* If we can't read the first line the file is probrably empty.
     * For now we consider this a fatal error.
     */
    if (fgets(buffer, LINE_BUFFER_LENGTH, fp) == NULL)
        FATAL("File %s seems empty.\n", filename);

    /* Emit a fatal error if there is not the sync sequence at the beginning
     * of the file.
     */
    if (strncmp(buffer, RECORD_SYNC_SEQUENCE,
                RECORD_SYNC_SEQUENCE_LENGTH) != 0)
        FATAL("The file %s must start with '%s'.\n",
              filename, RECORD_SYNC_SEQUENCE);

    while (fgets(buffer, LINE_BUFFER_LENGTH, fp) != NULL) {
        const char *p = buffer;

        if (strncmp(buffer, RECORD_FIELD_DAY,
                    RECORD_FIELD_DAY_LENGTH) == 0) {
            /* Skip 'day:' and following spaces */
            p += RECORD_FIELD_DAY_LENGTH + 1;
            SKIP_SPACES(p);

            record.day = TWO_DIGITS_TO_UINT(p[0], p[1]);

            continue;
        }

        if (strncmp(buffer, RECORD_FIELD_HOUR,
                    RECORD_FIELD_HOUR_LENGTH) == 0) {
            /* Skip 'hour:' and following spaces */
            p += RECORD_FIELD_HOUR_LENGTH + 1;
            SKIP_SPACES(p);

            record.hour = TWO_DIGITS_TO_UINT(p[0], p[1]);

            continue;
        }

        if (strncmp(buffer, RECORD_FIELD_ROOM_TYPE,
                    RECORD_FIELD_ROOM_TYPE_LENGTH) == 0) {
            /* Skip 'room_type:' and following spaces */
            p += RECORD_FIELD_ROOM_TYPE_LENGTH + 1;
            SKIP_SPACES(p);

            record.room_type = ((p[0] == 'R') ? RESTAURANT : PIZZERIA);

            continue;
        }

        if (strncmp(buffer, RECORD_FIELD_NAME,
                    RECORD_FIELD_NAME_LENGTH) == 0) {
            /* Skip 'name:' and following spaces */
            p += RECORD_FIELD_NAME_LENGTH + 1;
            SKIP_SPACES(p);

            strncpy(record.name, p, BOOKING_STRING_LENGTH);

            /* Replace newline with \0 */
            record.name[strcspn(record.name, "\n")] = '\0';

            continue;
        }

        if (strncmp(buffer, RECORD_FIELD_PEOPLE_COUNT,
                    RECORD_FIELD_PEOPLE_COUNT_LENGTH) == 0) {
            /* Skip 'name:' and following spaces */
            p += RECORD_FIELD_PEOPLE_COUNT_LENGTH + 1;
            SKIP_SPACES(p);

            record.people_count = TWO_DIGITS_TO_UINT(p[0], p[1]);

            continue;
        }

        /* This means that we're done reading the current record.
         * We can save it to the linked list.
         */
        if (strncmp(buffer, RECORD_SYNC_SEQUENCE,
                    RECORD_SYNC_SEQUENCE_LENGTH) == 0) {

            struct booking_list_el *el = calloc(1, sizeof(struct booking_list_el));
            el->_ = record;
            LIST_INSERT_LAST(list, el);

            continue;
        }
    }

    return list;
}
