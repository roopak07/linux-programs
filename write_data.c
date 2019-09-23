#include <unistd.h>
#include<stdio.h>
#include<fcntl.h> // for open,write,read 
#include<stdlib.h> //for exit  

int main()
{
 int fd = open("abc1.txt",O_RDWR|O_CREAT,0600);
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
 int ret=write(fd,"Hello world! this is my first program\n",40);
printf("ret(No:of bytes)=%d\n",ret);
if(ret<0)
printf("write failed\n");
else
printf("write sucess\n");
}

