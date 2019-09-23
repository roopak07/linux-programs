#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
void main()
{
int stat;
int id=fork();
printf("id of child:%d\n",id);
if(id==0)
 {
 printf("child process\n");
 exit(5);
 }
id=wait(&stat); // wait will return pid of the child process that has terminated
printf("id:%d	exit status:%d\n",id,WEXITSTATUS(stat));
}
