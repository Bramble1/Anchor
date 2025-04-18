
all: compile

#compiler and tools
CC = gcc
CFLAGS = -g -W

#source files
SRCS = main.c functions.h functions.c stack.h stack.c

#output binary
TARGET = anchor

compile:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

test:
	#using "check" command line tool

#Create a dev docker environment tailored to developng in C
