CC=gcc
CFLAGS=-g
LDFLAGS=-lpthread
#LDLIBS=
OBJS=mycp-adv.o
TARGET=mycp-adv

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $(SRCS) $(HEARS)
clean:
	rm -f *.o
	rm -f *.gch
	rm -f $(TARGET)
