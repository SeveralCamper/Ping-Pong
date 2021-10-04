CFLAGS = -Wall -Werror -Wextra
CC = gcc
TARGET = bin/ping_pong

all: $(TARGET)

$(TARGET): obj/ping_pong.o
	$(CC) $(CFLAGS) obj/ping_pong.o -o $@

obj/ping_pong.o :src/ping_pong.c
	$(CC) $(CFLAGS) -c src/ping_pong.c -o $@

run:
	./$(TARGET)

clean:
	find . -name "*.d" -exec rm {} \;
	find . -name "*.o" -exec rm {} \;
	find . -name "*.a" -exec rm {} \;
	rm bin/ping_pong

rebuild: clean all

.PHONY: clean run rebuild all