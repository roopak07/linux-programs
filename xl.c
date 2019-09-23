#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
void main()
{
char buf[24]="Hello world!";
/*open operation*/
int fd=open("abc.xls",O_WRONLY|O_CREAT,0600);
printf("fd=%d\n",fd);
if(fd>0)
printf("file opened\n");
else
printf("open error\n");
/*write operation*/
int ret=write(fd,buf,strlen(buf));
buf[ret]='\0';
printf("ret=%d\n",ret);
if(ret>0)
printf("write succes\n");
else
printf("write error\n");
close(fd);
/*read operation*/
fd=open("abc.txt",O_RDONLY);
printf("fd for reading file=%d\n",fd);
int ret1=read(fd,buf,24);
printf("ret1=%d\n",ret1);
//buf[ret1]='\0';
for(int i=0;i<ret1;i++)
 {
 printf("%c",buf[i]);
 }
printf("\n");
if(ret1>0)
printf("read success\n");
else
printf("read fail\n");
close(fd);
}
