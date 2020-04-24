#include<signal.h>
#include<stdio.h>
void main()
{
int ret,pid;
printf("Enter pid of the process to kill:");
scanf("%d",&pid);
ret=kill(pid,9);
if(ret>=0)
	printf("process killed \n");
else
	printf("kill error \n");
}
