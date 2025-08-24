#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#ifndef FM_H
#define FM_H
extern char *Stacks;
extern char *config;
extern char *default_stack;

#include "../misc/misc.h"

typedef struct 
{
	char File[100];
	char path[100];
}file;

enum Action
{
	LIST,
	SELECT
};


void create_directory();
void exec_dir(enum Action option, file *info);
void delete_stack(Args *args);
void select_stack();
void get_selected_stack(char *stack);
#endif
