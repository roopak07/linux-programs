#include<stdio.h>
#include<fcntl.h>
void main()
{
 int fd=open("file.txt",O_RDWR|O_CREAT,0666);
 if(fd>0)
	printf("file open sucess");
 else
	printf("file open ERROR !");
}
