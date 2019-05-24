CFLAGS:= -std=c99 -pedantic -g -Wall -Wextra
LDFLAGS:=

.PHONY: all
all: test_list test_bitmask

test_list: test_list.c ../list.h
	$(CC) $(CFLAGS) -o $@ $<

test_bitmask: test_bitmask.c ../bitmask.h
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f test_list
	rm -f test_bitmask
