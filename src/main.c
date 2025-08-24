#include "file_management/fm.h"
#include "stack_management/stack_interface.h"
#include "misc/misc.h"
#include <unistd.h>


int main(int argc,char *argv[])
{
	/*Initial setup, setting up buffers to be used throughout program.
	 * creating a stack object
	 * creating a directory to store stacks*/
	Stack st = init_stack();
	create_directory();

	Mem mem = {0};	
	/*obtain the currently selected stackfile to load/save our stack to*/
	char *stackfile = mem.buffer[0];
	get_selected_stack(stackfile);

	if(argc>1)
	{
		if(strcmp(argv[1],"pop")==0)
		{
			/*pop the latest anchored directory, reverting to the previous saved directory.*/
			delete_anchor(&st,stackfile);
			update_alias(&st,stackfile,&mem);
		}
		if(strcmp(argv[1],"list")==0)
		{
			/*print all directories in the stack from the specified stackfile*/
			display_anchors(&st,stackfile);
		}
		if(strcmp(argv[1],"switch")==0)
		{
			/*swap the current anchored directory with a different directory in stack making it now
			 * the new anchored directory*/
			int index=0;
			printf("Enter index: ");
			scanf("%d",&index);
			printf("stackfile=%s\n",stackfile);
			switch_anchor(&st,index,stackfile,&mem);
			update_alias(&st,stackfile,&mem);
		}
		if(strcmp(argv[1],"peek")==0)
		{
			//alter so it returns to stdout the top of the stack, being the anchored directory, hot fixed
			char *directory = mem.buffer[0];
			memset(directory,'\0',100);
			peek(&st,directory);
			printf("current: %s",directory);
		}
		if(strcmp(argv[1],"load")==0)
		{
			//this could launch into a while loop to manage stack files, so can choose one to load, delete. Could also be the same for managing stack entries
			/*load a new stackfile*/
			char buffer[100]="\0";

			memset(stackfile,'\0',100);
			file info;
			exec_dir(LIST,&info);
			printf("\nStackname(d - delete): ");
			fgets(stackfile,99,stdin);
			strip_newline(stackfile);

			if(stackfile[0] == 'd' && stackfile[1]==' ')
			{
				/*extract all the filename arguments we wish to delete and send a pointer to the first*/
				/*place this function the misc.c*/
				char *ptr = (char *)&stackfile[2];
				Args args = {0};
				extract_arguments(ptr,&args);

				delete_stack(&args);

				exit(EXIT_SUCCESS);

						
						
			}

			select_stack(stackfile);



		}
		
	}
	else
	{
		/*add current directory to the top of the stack, and thus the new anchored directory we can quickly cd into it with alias key*/
		anchor(&st,stackfile);	
		update_alias(&st,stackfile,&mem);

		exit(EXIT_SUCCESS);		
	}

	return 0;	
}


