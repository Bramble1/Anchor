#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20

/*Data structures*/
typedef struct
{
	char stack[MAX][100];
	int top;
}Stack;

/*Stack operations*/
Stack init_stack();
void push(Stack *st, char *directory);
void pop(Stack *st,char *directory);
void peek(Stack *st,char *directory);
void display(Stack *st);

/*file persistence*/
void save_structure(Stack *st,char *filename);
Stack load_structure(char *filename);
