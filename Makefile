CC     = gcc
CFLAGS = -Wall -Wextra -g

OBJS   = main.o board.o input.o
TARGET = dotsandboxes

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c board.h input.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)
