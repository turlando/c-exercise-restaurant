CFLAGS:= -std=c99 -pedantic -g -Wall -Wextra

.PHONY: all
all: test_bitmask test_list test_timetable

test_bitmask: test_bitmask.c ../bitmask.h
	$(CC) $(CFLAGS) -o $@ $<

test_list: test_list.c ../list.h
	$(CC) $(CFLAGS) -o $@ $<

test_timetable: test_timetable.c ../timetable.c ../timetable.h test_timetable.txt
	$(CC) $(CFLAGS) -o $@ $< ../timetable.c

.PHONY: clean
clean:
	rm -f test_bitmask
	rm -f test_list
	rm -f test_timetable
