//This file implements the functionality of tee command. Multiple file names can be passed as argument and data from stdinput will be copied to standart output as well as files provided as argument.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_READ 1000

int main(int argc, char * argv[])
{
	int fd[argc],i;
	char * buffer;
	buffer = (char *)malloc((MAX_READ+1) * sizeof(char));
	for (i=1;i<argc;i++)
	{
	        fd[i-1] = open(argv[i],O_WRONLY);
	        if (fd[i-1] == -1)
	        {
		        perror("Open:");
			exit(1);
	        }
	}
	while(1)
	{
		read(0,(void *)buffer,MAX_READ);
		if (strlen(buffer) == 0)
		{
			for (i=1;i<argc;i++)
			{	
			        write(fd[i-1],(void *)buffer,strlen(buffer));
			}
			write(1,(void *)buffer,strlen(buffer));
			memset(buffer,0, MAX_READ);
			break;
		}
		else
		{
			for (i=1;i<argc;i++)
			{	
			        write(fd[i-1],(void *)buffer,strlen(buffer));
			}
			write(1,(void *)buffer,strlen(buffer));
			memset(buffer,0, MAX_READ);
		}
	}
	for (i=1;i<argc;i++)
	{
		close(fd[i]);
	}
}
