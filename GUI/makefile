CC = gcc

all:
	${CC} `pkg-config --cflags gtk+-3.0` -o main main.c `pkg-config --libs gtk+-3.0`
	./main