CC=gcc
CFLAGS=-Wall -std=c99

.PHONY: test memtest clean 

countdown: countdown.o timefmt.o
	$(CC) $(CFLAGS) $^ -o countdown

test: test_timefmt
	./test_timefmt

test_timefmt: test_timefmt.o timefmt.o
	$(CC) $(CFLAGS) $^ -o test_timefmt

memtest: test_timefmt countdown
	valgrind ./test_timefmt
	valgrind ./countdown 3s

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f countdown test_timefmt *.o
