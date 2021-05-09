//Write a program in C to read the file and store the lines into an array.
#include "uniheader.h"
#define MAX_READ 500
int main(int argc, char * argv[])
{
	int fd;
	char *buffer,*buffer1;
	buffer = (char *)malloc((MAX_READ + 1) * sizeof(char));
	fd = open(argv[1],O_RDONLY);
	if (fd == -1)
	{
		perror("Open: ");
		exit(1);
	}
	while(read(fd,(void *)buffer,MAX_READ)!=0)
	{
		buffer1 = (char *)realloc(buffer1,strlen(buffer));
		strcpy(buffer1,buffer);
	}
	printf("%s",buffer1);
	close(fd);
}
