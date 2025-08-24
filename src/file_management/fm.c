#include "fm.h"
#include "../misc/misc.h"
char *Stacks = ".stacks\0";
char *config = ".config\0";
char *default_stack = "general.dat\0";

void create_directory()
{
	char *home = getenv("HOME");
	char buf[100]="\0";
	sprintf(buf,"%s/%s",home,Stacks);

	if(mkdir(buf,0755)==-1)
	{
		/*perror("mkdir");
		exit(EXIT_FAILURE); */
	}

	//update config with default stack.dat
	memset(buf,'\0',99);
	sprintf(buf,"%s/%s/%s",home,Stacks,config);
	FILE *fd = fopen(buf,"a+");
	if(!fd)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	fseek(fd,0,SEEK_END);
	long size = ftell(fd);
	if(size==0){
		rewind(fd);
		memset(buf,'\0',99);
		sprintf(buf,"%s/%s/%s",home,Stacks,default_stack);
		fwrite(buf,sizeof(char),strlen(buf),fd);
	}

	fclose(fd);
}


void exec_dir(enum Action option,file *info)
{
	char buf[100]="\0";
	char *home = getenv("HOME");
	sprintf(buf,"%s/%s",home,Stacks);

	DIR *dir = opendir(buf);
	if(!dir)
	{
		perror("opendir");
		exit(EXIT_FAILURE);
	}

	struct dirent *entry;
	while(( entry=readdir(dir)) != NULL)
	{
		if(strcmp(entry->d_name,".")==0 || strcmp(entry->d_name,"..")==0 || strcmp(entry->d_name,".config")==0)
			continue;

		switch(option)
		{
			case LIST:
				printf("%s\n",entry->d_name);
				break;
			case SELECT:
				if(strcmp(entry->d_name,info->File)==0)
				{
					printf("[+]Match found![+]\n");
					sprintf(info->path,"%s/%s/%s\0",home,Stacks,entry->d_name); //absolute path required
				}	
				break;
		}
	}
}

void delete_stack(Args *args)
{
	file info;
	
	for(int i=0;i<=args->count;i++)
	{
		strcpy(info.File,args->arguments[i]);
		exec_dir(SELECT,&info);
		
		if(strlen(info.path)>0)
			if(remove(info.path)==-1)
			{
				perror("remove");
				exit(EXIT_FAILURE);
			}
		memset(info.File,'\0',99);
	}	
}

void select_stack(char *filename)
{
	//if it exists using the exec function with select , then we can update for now, just store the current stack filename in a simple textfile
	file info;
	strcpy(info.File,filename);
	exec_dir(SELECT,&info);

	char buf[100]="\0";
	char *home = getenv("HOME");

	//if it doesn't exist just append it to the config anyway to create
	if(!strlen(info.path)>0){
		sprintf(info.path,"%s/%s/%s",home,Stacks,filename);			
	}

	//commenting this out, as even if it doesn't exist, the program will create it
	if(strlen(info.path)>0){

	char buf[100]="\0";
	char *home = getenv("HOME");
	sprintf(buf,"%s/%s/%s",home,Stacks,config);
	//update config
	FILE *fd = fopen(buf,"w+");
	if(!fd)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	
	//printf("[*]Writing: %s\n",info.path);
	fwrite(info.path,sizeof(char),strlen(info.path),fd);

	fclose(fd);
	}
	
}

void get_selected_stack(char *stack)
{
	char buf[100]="\0";
	char *home = getenv("HOME");
	sprintf(buf,"%s/%s/%s",home,Stacks,config);

	FILE *fd = fopen(buf,"r");
	if(!fd)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	fseek(fd,0,SEEK_END);
	long size = ftell(fd);
	rewind(fd);

	fread(stack,sizeof(char),size,fd);

	fclose(fd);
}

