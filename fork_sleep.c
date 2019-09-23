#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{
int id=fork();
if(id==0)
 {
 sleep(30);
 printf("child process\n");
 }
else
 {
 sleep(20);
 printf("parent processs\n");
 }
}
