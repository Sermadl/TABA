CC=gcc
CFLAGS=-c -g -Wall
OBJS=main2.o test1.o test2.o
SRCS=test1.c test2.c
HEARS=test1.h test2.h
LIBS=-lpthread
TARGET=result.out

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $(SRCS) $(HEARS)

clean:
	rm -f *.o
	rm -f *.gch
	rm -f $(TARGET)
