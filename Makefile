CC = gcc
Cflags = -Wall -Wextra -O2
OBJECTS = struct.o command.o list.o colors.o messages.o tables.o main.o

.DEFAULT_GOAL = sgbd
.PHONY = clean


sgbd: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm $(OBJECTS) || exit 0