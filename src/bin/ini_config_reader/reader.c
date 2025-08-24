#include <stdio.h>

#define LIMIT 100
#define SPACE 32
#define EQUALS 61

typedef struct 
{
	char buffer[LIMIT];
	char *rear;
} String;


void extract(String *key,String *value,char *buffer)
{
	key->rear = (char *)&key->buffer;
	value->rear = (char*)&value->buffer;
	String *toggle = key; 

	char *ptr = buffer;
	while(*ptr != '\0')
	{
		switch(*ptr)
		{
			case SPACE:
				ptr++;
				break;
			case EQUALS:
				toggle = value;
				ptr++;
				break;
			default:
				*toggle->rear++ = *ptr;
				ptr++;
				break;
		}
					
	}

}

int main()
{
	char *example = "stackfile = general.dat\0";

	String key;
	String value;
	
	extract(&key,&value,example);

	printf("%s\n",key.buffer);
	printf("%s\n",value.buffer);

	return 0;
}
