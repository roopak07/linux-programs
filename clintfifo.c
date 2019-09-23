#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/stat.h>
void main()
{
char buf[20];
int servfd=open("servfifo",O_WRONLY);
scanf("%s",buf);
write(servfd,buf,strlen(buf));


int clintfd=open("clintfifo",O_RDONLY);
if(clintfd<0)
 {
 int ret=mkfifo("clintfifo",0640);
 if(ret<0)
  {
  printf("mkfifo Error");
  return;
  }
  else
  {
  clintfd=open("clintfifo",O_RDONLY);
  }
 }

read(clintfd,buf,20);
printf("recived from server : %s \n",buf);
}
