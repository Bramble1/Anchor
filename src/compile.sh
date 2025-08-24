#!/bin/bash

gcc -W -g -o anchor main.c \
	file_management/fm.c \
	stack_management/stack.c stack_management/stack_interface.c \
	misc/misc.c

