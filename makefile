CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g
SRCS = push_swap.c src/funcs.c
TARGET = push


push: push_swap.c # target only rebuild if push_swap.c change [push_swap rebuild if push_swap.c change]
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)



fclean: # to remove everything [executable and object filies]
	rm -f $(TARGET)
	rm -f *.o

clean: # remove just excutable
	rm -f $(TARGET) 


# all usualy define the depencies of all targets
all: $(TARGET) # we are here build push_swap.c








