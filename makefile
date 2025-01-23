CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g
SRCS = main.c
TARGET = main


$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)










