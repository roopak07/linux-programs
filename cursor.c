#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
char buf[30]="cursor test";
int fd=open("cursor.txt",O_CREAT|O_RDWR,0600);
if(fd>0)
printf("open sucess\n");
else
printf("open error\n");
int rw=write(fd,buf,strlen(buf));
if(rw>0)
printf("write sucess\n");
else
printf("write error\n");
lseek(fd,0,SEEK_SET); // sets postion of cursor to 0 
int re=read(fd,buf,strlen(buf));
if(re>0)
printf("read sucess\n");
else
printf("read error\n");
close(fd);
}
