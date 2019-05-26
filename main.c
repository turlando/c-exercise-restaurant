#include <stdio.h>
#include "utils.h"
#include "bitmask.h"
#include "room.h"
#include "timetable.h"
#include "booking.h"

#define HELP_ARG_FMT "  %s         %s\n"

#define TIMETABLE_FILE "resources/timetable.txt"
#define BOOKINGS_FILE  "resources/bookings.txt"

void print_help() {
    printf(HELP_ARG_FMT, "-r         ", "Print rooms and tables");
    printf(HELP_ARG_FMT, "-t         ", "Print timetable");
    printf(HELP_ARG_FMT, "-a DAY HOUR", "Print available tables on a "
           "given day and hour (e.g.: '-a 01 19')");
}

void print_rooms() {
    for (unsigned int room_id = 0; room_id < ROOM_COUNT; ++room_id) {
        printf("===== Room %c %s - %02d %s =====\n",
               rooms[room_id].name,
               rooms[room_id].type == RESTAURANT ? "(RESTAURANT)"
                                                 : "(PIZZERIA)  ",
               rooms[room_id].tables_count,
               rooms[room_id].tables_count == 1 ? "table " : "tables");

        for (unsigned int table_id = 0;
             table_id < rooms[room_id].tables_count;
             ++table_id) {
            printf("Table %02d  Seats %02d       ",
                   table_id,
                   rooms[room_id].tables[table_id].seats);

            if ((table_id != 0
                 && table_id != rooms[room_id].tables_count - 1
                 && table_id % 2 != 0))
                putchar('\n');
        }

        putchar('\n');

        if (room_id != ROOM_COUNT - 1)
            putchar('\n');
    }
}

void print_timetable(struct timetable timetable) {
    for (unsigned int day = 1; day < TIMETABLE_LENGTH; ++day) {

        printf("Day %02d   ", day);
        if (timetable._[day] == TIMETABLE_DAY_CLOSED) {
            printf("   Closed\n");
            continue;
        }

        int from = -1;
        int to   = -1;

        for (unsigned int hour = 0; hour < TIMETABLE_HOURS_IN_DAY; ++hour)
            if ((1U << hour) & timetable._[day]) {
                if (from == -1)
                    from = hour;

                if (! ((1U << (hour + 1)) & timetable._[day])) {
                    to = hour + 1;
                    printf("%2d:00 - %2d:00   ", from, to);

                    from = to = -1;
                }
            }

        putchar('\n');
    }
}

void print_available_tables(struct room_tables_availability availability) {
    for (unsigned int room_id = 0; room_id < ROOM_COUNT; ++room_id) {
        printf("===== Room %c %s =====\n",
               rooms[room_id].name,
               rooms[room_id].type == RESTAURANT ? "(RESTAURANT)"
                                                 : "(PIZZERIA)  ");

        for (unsigned int table_id = 0;
             table_id < rooms[room_id].tables_count;
             ++table_id) {
            printf("Table %02d  Seats %02d  %s       ",
                   table_id,
                   rooms[room_id].tables[table_id].seats,
                   (availability._[room_id] & MASK_BIT(table_id)) ? "BUSY "
                                                                  : "AVAIL");

            if ((table_id != 0
                 && table_id != rooms[room_id].tables_count - 1
                 && table_id % 2 != 0))
                putchar('\n');
        }

        putchar('\n');

        if (room_id != ROOM_COUNT - 1)
            putchar('\n');
    }
}

int main(int argc, char **argv) {
    if ((argc < 2
         || (argv[1][0] == '-' && argv[1][1] == 'h'))) {
        print_help();
        return 0;
    }

    for (int arg_i = 1; arg_i < argc; ++arg_i) {
        if (argv[arg_i][0] != '-' || argv[arg_i][1] == '\0')
            FATAL("%s\n", "Argument expected.");

        switch (argv[arg_i][1]) {
            case 'r':
                print_rooms();
                return 0;

            case 't': {
                struct timetable timetable = timetable_read_file(TIMETABLE_FILE);
                print_timetable(timetable);
                return 0;
            }

            case 'a': {
                if (argc < 4)
                    FATAL("%s\n", "Argument expected.");

                char *arg_day = argv[arg_i + 1];
                char *arg_hour = argv[arg_i + 2];

                unsigned int day = TWO_DIGITS_TO_UINT(arg_day[0], arg_day[1]);
                unsigned int hour = TWO_DIGITS_TO_UINT(arg_hour[0], arg_hour[1]);

                booking_list_t bookings = booking_read_file(BOOKINGS_FILE);
                struct room_tables_availability availability =
                    booking_get_available_tables(bookings, day, hour);

                print_available_tables(availability);

                booking_list_destroy(bookings);

                return 0;
            }

        }
    }

    return 0;
}
