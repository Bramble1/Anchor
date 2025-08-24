#include "misc.h"

void strip_newline(char *buffer)
{
	for(int i=strlen(buffer);i>=0;i--)
		if(buffer[i]=='\n')
			buffer[i]='\0';
}


void extract_arguments(char *buffer,Args *args)
{

	int index1;int index2;
	index1 = index2 = 0;

	for(int i=0;i<(int)strlen(buffer);i++)
	{
		if(buffer[i]==' ')
		{
			if(buffer[i+1]=='\n')
				break;
			args->count = index1 +=1;
			index2 = 0;
			i++;

			//if we run out of space for arg space do something here
		}

		args->arguments[index1][index2] = buffer[i];
  		index2 +=1;


	}				
}
