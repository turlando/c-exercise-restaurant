#include "../timetable.h"
#include <assert.h>
#include <stdio.h>

#define BINARY(a,b,c,d,e,f,g,h) 0b##a##b##c##d##e##f##g##h

#define TIMETABLE_FILE "test_timetable.txt"

void print_timetable(struct timetable t) {
    /* Loop over each day in the timetable.
     * We skip the first element (indexed by 0) since
     * the first day of the month is indexed by 1 and
     * since it doesn't contain any meaningful information.
     */
    for (unsigned int i = 1; i < TIMETABLE_LENGTH; ++i) {

        printf("Day: %02u\n", i);

        /* If all the bits of the day are set to zero then
         * the restaurant is closed.
         */
        if (t._[i] == 0U)
            printf("Closed");

        /* Otherwise we print when the restaurant is open in
         * the current day.
         */
        else
            /* We iterate over each hour n in a day (from 0 to 23)
             * and we print if the nth bit in the integer is flipped.
            */
            for (unsigned int j = 0; j < TIMETABLE_HOURS_IN_DAY; ++j)
                if ((1U << j) & t._[i])
                    printf("%2d:00-%2d:00 ", j, j + 1);

        printf("\n---\n");
    }
}

int main(void) {
    struct timetable timetable = timetable_read_file(TIMETABLE_FILE);
    assert(timetable._[1] == BINARY(0000,0000,0011,1000,0000,0000,0000,0000));
    assert(timetable._[2] == BINARY(0000,0000,0011,1000,0111,0000,0000,0000));
    print_timetable(timetable);
    return 0;
}
