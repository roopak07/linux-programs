#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include <ctype.h>
void main()
{
//char readbuf[100],writebuf[100];
char buf[100];
int fds[2];
pipe(fds);
int id=fork();
if(id==0)
 {
 close(fds[1]);
 while(1)
  {
  int n=read(fds[0],buf,100);
  printf("read from fds[0] and output to screen:\n");
  for(int i=0;i<n;i++)
   {
   buf[i]=toupper(buf[i]);
   }
   printf("%s\n",buf);
  }
 }
close(fds[0]);
while(1)
 { 
 scanf("%s",buf);
 write(fds[1],buf,strlen(buf)+1);
 printf("wrote to fds[1]:\n");
 }
}


