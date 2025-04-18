#include "stack.h"

Stack init_stack()
{
	Stack st;
	st.top=-1;
	return st;	
}

void push(Stack *st, char *directory) {
  if (st->top >= MAX-1) {
    printf("[-]Stack overflow\n");
    exit(EXIT_FAILURE);
  }

  st->top += 1;
  strcpy(st->stack[st->top],directory);
}

void pop(Stack *st,char *directory)
{
	if(st->top==-1)
	{
		printf("[-]Stack underflow\n");
		exit(EXIT_FAILURE);
	}

	strcpy(directory,st->stack[st->top]);
	st->top--;
}

void peek(Stack *st,char *directory)
{
	strcpy(directory,st->stack[st->top]);
}

void display(Stack *st)
{
	int i;
	for(i=0;i<st->top;i++)
	{
		printf("[%d]%s\n",i,st->stack[i]);
	}
	if(i==st->top)
		printf("\033[33m[%d]%s\033[0m\n",i,st->stack[i]);

}

void save_structure(Stack *st,char *filename)
{
	char path[150]="\0";
	sprintf(path,"%s/%s",getenv("HOME"),filename);

	FILE *fd=fopen(path,"wb");
	if(fd==NULL)
	{
		perror("Error opening file for writing");
		exit(EXIT_FAILURE);
	}

	fwrite(st,sizeof(Stack),1,fd);
	
	fclose(fd);
}

Stack load_structure(char *filename)
{
	char path[150]="\0";
	sprintf(path,"%s/%s",getenv("HOME"),filename);

	Stack st = init_stack();
	FILE *fd=fopen(path,"rb");
	if(fd==NULL)
		return st;


	fread(&st,sizeof(Stack),1,fd);	
	fclose(fd);
	return st;	
}


