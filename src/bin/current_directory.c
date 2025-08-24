#include <stdio.h>
#include <unistd.h>

int main()
{
	char directory[100]="\0";
	getcwd(directory,sizeof(directory));
	printf("%s\n",directory);

	return 0;
}
