//This program is to show use of write function. In thi C library functions are used instead of system calls.


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	FILE *fptr;
	fptr = fopen("./demo_file.txt","w");
	if (fptr == NULL)
	{
		printf("Error!!\n");
		exit(1);
	}
	printf("Enter numbers: ");
	scanf("%d",&num);

	fprintf(fptr,"%d",num);
	fclose(fptr);
}
