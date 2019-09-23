#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
int fd=open("dup2.txt",O_CREAT|O_RDWR,0600);
if(fd>0)
printf("open sucess\n");
else
printf("open error\n");
printf("sample program1\n");
printf("sample program2\n");
dup2(fd,1);
printf("sample program3\n");
printf("sample program4\n");

}
