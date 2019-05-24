#include "../timetable.h"
#include <assert.h>
#include <stdio.h>

#define BINARY(a,b,c,d,e,f,g,h) 0b##a##b##c##d##e##f##g##h

#define TIMETABLE_FILE "test_timetable.txt"

void print_timetable(struct timetable t) {
    for (unsigned int i = 0; i < 32; ++i) {
        printf("Day: %02u\n", i);
        if (t._[i] == 0) {
            printf("Closed");
        } else {
            for (unsigned int j = 0; j < 24; ++j) {
                if ((1U << j) & t._[i]) {
                    printf("%2d:00-%2d:00 ", j, j + 1);
                }
            }
        }
        printf("\n---\n");
    }
}

int main(void) {
    struct timetable timetable = timetable_read_file(TIMETABLE_FILE);
    assert(timetable._[1] == BINARY(0000,0000,0011,1000,0011,0000,0000,0000));
    assert(timetable._[2] == BINARY(0000,0000,0011,1000,0000,0000,0000,0000));
    print_timetable(timetable);
    return 0;
}
