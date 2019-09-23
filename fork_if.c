#include<stdio.h>
#include<unistd.h>
void main()
{
printf("test1\n");
int id=fork();
printf("test2 \n");
printf("id=%d\n",id);
if(id==0)
printf("child process\n");
else
printf("parent process\n");
}
