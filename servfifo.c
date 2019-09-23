#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include <ctype.h>
#include <sys/stat.h>
void main()
{
char buf[20];
int servfd=open("servfifo",O_RDONLY);
if(servfd<0)
 {
 int ret=mkfifo("servfifo",0640);
 if(ret<0)
  {
  printf("mkfifo Error");
  return;
  }
  else
  {
  servfd=open("servfifo",O_RDONLY);
  }
 }
 int ret1=read(servfd,buf,20);
 buf[ret1]='\0';
 printf("recived data from clint:%s \n",buf);
 for(int i=0;i<ret1;i++)
   {
   buf[i]=toupper(buf[i]);
   }
  // printf("modified recived data:%s \n",buf);
 int clintfd=open("clintfifo",O_WRONLY);
 write(clintfd,buf,strlen(buf)+1);
}
