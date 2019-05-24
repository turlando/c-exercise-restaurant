CFLAGS:= -std=c99 -pedantic -g -Wall -Wextra

.PHONY: all
all: test_bitmask test_list test_timetable test_booking

test_bitmask: test_bitmask.c ../bitmask.h
	$(CC) $(CFLAGS) -o $@ $<

test_list: test_list.c ../list.h
	$(CC) $(CFLAGS) -o $@ $<

test_timetable: test_timetable.c ../timetable.c ../timetable.h test_timetable.txt
	$(CC) $(CFLAGS) -o $@ $< ../timetable.c

test_booking: test_booking.c ../booking.c ../booking.h test_booking.txt
	$(CC) $(CFLAGS) -o $@ $< ../booking.c

.PHONY: clean
clean:
	rm -f test_bitmask
	rm -f test_list
	rm -f test_timetable
	rm -f test_booking
