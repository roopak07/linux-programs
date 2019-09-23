#include <unistd.h>
#include<stdio.h>
#include<fcntl.h> // for open,write,read 
#include<stdlib.h> //for exit  

int main()
{
    int fd = open("abc.txt",O_RDWR|O_CREAT,0660);
	printf("%d\n",fd);    
	if(fd<0)
	{
	printf("open error");
	exit(1);
	}
	else
	{
	printf("file created and opened\n");
	}
}
