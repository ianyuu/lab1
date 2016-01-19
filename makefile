
CC = gcc
CFLAGS = -ansi

datest: driver.o datime.o time.o common.o
	$(CC) -o datest driver.o datime.o time.o common.o

driver.o: datime.h time.h

datime.o: datime.h common.h time.h

time.o: time.h common.h

clean:
	rm -f *.o

real_clean: clean
	rm -f datest
