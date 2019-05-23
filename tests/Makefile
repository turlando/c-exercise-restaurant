CFLAGS:= -std=c99 -pedantic -g -Wall -Wextra
LDFLAGS:=

test_list: test_list.c ../list.h
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f test_list
