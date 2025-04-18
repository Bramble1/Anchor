#include "functions.h"
#include <unistd.h>

int main(int argc,char *argv[])
{

	int arguments=0;
	Stack st = init_stack();

	if(argc>1)
	{
		if(strcmp(argv[1],"pop")==0)
		{
			delete_anchor(&st);
			update_alias(&st);
		}
		if(strcmp(argv[1],"list")==0)
		{
			display_anchors(&st);
		}
		if(strcmp(argv[1],"switch")==0)
		{
			int index=0;
			printf("Enter index: ");
			scanf("%d",&index);
			switch_anchor(&st,index);
			update_alias(&st);
		}
	}
	else
	{
		anchor(&st);	
		update_alias(&st);

		exit(EXIT_SUCCESS);		
	}

	return 0;	
}


