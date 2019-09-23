#include <unistd.h>
#include<stdio.h>
#include<fcntl.h> // for open,write,read 
#include<stdlib.h> //for exit  

int main()
{
    int fd = open("abc1.txt",O_RDWR);
	printf("%d\n",fd);    
	if(fd<0)
	{
	printf("open error\n");
	exit(1);
	}
	else
	{
	printf("file opened\n");
	}
	int fd1=open("abcd.txt",O_RDONLY);
	printf("%d\n",fd1);
	if(fd1<0)
	{
	printf("open error\n");
	exit(1);
	}
	else
	{
	printf("file opened\n");
	}
}
