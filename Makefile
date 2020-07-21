CC=gcc
CFLAGS=-Wall -std=c99

.PHONY: test clean

countdown: countdown.o timefmt.o
	$(CC) $(CFLAGS) $^ -o countdown

test: test_timefmt
	./test_timefmt

test_timefmt: test_timefmt.o timefmt.o
	$(CC) $(CFLAGS) $^ -o test_timefmt

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f countdown test_timefmt *.o
