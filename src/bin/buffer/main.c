#include <stdio.h>
#include <string.h>

void func(char *buffer)
{
	strcpy(buffer,"hello\0");
}

int main()
{

	char buffer[50]="\0";
	func(buffer);

	printf("%s\n",buffer);

	return 0;
}
