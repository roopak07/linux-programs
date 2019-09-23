#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{
int id,count=0;
printf("fork process is starting\n");
printf("fork process id=%d\n",id);
id=fork();
if(id)
 {
 while(count<50)
  { 
  count++;
  printf("my child process id=%d\n",id);
  sleep(3);
  }
 }
if(id==1)
 {
 while(count<20)
  { 
  count++;
  printf("child process id=%d\n",id);
  sleep(5);
  }
 }

}
