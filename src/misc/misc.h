#ifndef _MSC_H
#define _MSC_H

#include<stdio.h>
#include<string.h>

void strip_newline(char *buffer);


typedef struct
{
	char buffer[3][100];
} Mem;

typedef struct
{
	char arguments[10][50];
	int count;
}Args;

void extract_arguments(char *buffer,Args *args);
/*char *get_available_buffer(Mem *mem)
{
	for(int i=0;i<=mem->buffer;i++)
	{
		if(buffer[i]=='\0')
			return buffer[i];
	} 	
}*/

#endif
