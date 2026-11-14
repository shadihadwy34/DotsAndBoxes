CC     = gcc
CFLAGS = -Wall -Wextra -g

OBJS   = main.o board.o input.o game.o
TARGET = dotsandboxes

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c board.h input.h game.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)
