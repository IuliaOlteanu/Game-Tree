CC = gcc
CFLAGS = -g -Wall

build: minimax.c
	$(CC)  minimax.c -o minimax $(CFLAGS)
clean :
	rm -f minimax
