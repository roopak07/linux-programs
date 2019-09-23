#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
int fds[2];
pipe(fds);
int id=fork();
if(id==0)
 {
 close(fds[1]);
 while(1)
  {
  printf("child processos:\n");
  }
 }
close(fds[0]);
while(1)
 { 
 printf("parent processos\n");
 }
}


