CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g
SRCS = main.c
TARGET = main


main: main.c # target only rebuild if main.c change [main rebuild if main.c change]
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)



fclean: # to remove everything [executable and object filies]
	rm -f $(TARGET)
	rm -f *.o

clean: # remove just excutable
	rm -f $(TARGET) 









