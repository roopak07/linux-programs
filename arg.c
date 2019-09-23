#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
main(int argc,char *argv[])
{
int fd,ret;
char buf[20];
if(argc!=2)
 {
 printf("invalid input\n");
 exit(1);
 }
fd=open(argv[1],O_RDONLY);
if(fd<0)
 {
 printf("file doesnot exist\n");
 exit(2);
 }
ret=read(fd,buf,19);
if(ret<0)
 {
 printf("unable to read the data \n");
 exit(3);
 }
buf[ret]='\0';
printf("%s \n",buf);
if(close(fd)<0)
 {
 printf("unable to close the file");
 exit(4);
 }
}
