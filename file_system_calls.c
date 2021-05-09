// This function is written to show use of write system call. In this file instead of library functions system calls are used.

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int buffer[500];
int numread;
int main(int argc, char * argv[])
{
	int fd = open("./demo_file.txt",O_RDWR);
	while(numread = read(fd,(void *)buffer,1) != 0)
	{
		printf("%c\n",*buffer);
	}
	close(fd);
}
