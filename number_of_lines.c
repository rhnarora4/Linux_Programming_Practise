//Write a program to find number of lines in test file
#include "uniheader.h"
#define MAX_READ 100
int main(int argc, char * argv[])
{
	int fd, num=0,i=0;
	char buffer[100];
	fd = open(argv[1],O_RDONLY);
	if (fd == -1)
	{
		perror("Open: ");
		exit(1);
	}
	while(read(fd,(void *)buffer, MAX_READ) != 0)
	{
		for (i=0;i<strlen(buffer);i++)
		{
			if (buffer[i] == '\n')
			{
				num++;
			}
		}
		memset(buffer,0,MAX_READ);
	}
	printf("Number of new lines in enetered file is: %d\n",num);
	close(fd);
}
