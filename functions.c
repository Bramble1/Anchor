#include "functions.h"
#include <unistd.h>
#include <sys/ioctl.h>

void spit_command(Stack *st)
{
	char command[150]="\0";
	char anchor[100]="\0";
	peek(st,anchor);

	sprintf(command,"cd %s\n",anchor);
	for(char *p=command;*p;++p)
		ioctl(STDIN_FILENO,TIOCSTI,p);
}

void anchor(Stack *st)
{
	char directory[100]="\0";
	if(getcwd(directory,sizeof(directory))==NULL)
	{
		perror("getcwd():");
		exit(EXIT_FAILURE);
	}

	*st = load_structure(FILENAME);	
	push(st,directory);
	save_structure(st,FILENAME);

}

void delete_anchor(Stack *st)
{
	*st = load_structure(FILENAME);
	char directory[100]="\0";
	pop(st,directory);
	printf("Removed:%s\n",directory);
	save_structure(st,FILENAME);

	spit_command(st);
}

void display_anchors(Stack *st)
{
	*st = load_structure(FILENAME);
	display(st);
}

void display_current(Stack *st)
{
	char directory[100]="\0";
	peek(st,directory);
	printf("current:%s\n",directory);
}

void switch_anchor(Stack *st,int index)
{
	//need to save and load the structure for persistence
	*st = load_structure(FILENAME);

	char directory[100]="\0";
	strcpy(directory,st->stack[index]);

	//shift the directories down one to the left to accomodate the most recent index chosen
	for(int i=index;i<st->top;i++)
	{
		strcpy(st->stack[i],st->stack[i+1]);
	}
	st->top-=1;
	push(st,directory);

	save_structure(st,FILENAME);

	spit_command(st);

}


void update_alias(Stack *st)
{
	*st = load_structure(FILENAME);

	char directory[100]="\0";
	char command[150]="\0";

	peek(st,directory);

	sprintf(command,"grep -q '^alias d=' ~/.bashrc && sed -i 's|^alias d=.*|alias d=\"cd %s\"|' ~/.bashrc || echo 'alias d=\"cd %s\"' >> ~/.bashrc",directory,directory);


	//using bash idioms coupled with grep and sed
	if(system(command)==-1)
	{
		perror("System command failed:");
		exit(EXIT_FAILURE);
	}
} 

