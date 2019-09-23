#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
int id=fork();
switch(id)
 {
 case -1:
	printf("error\n");
	break;
 case 0:
	printf("child process\n");
	printf("id=%d\n",id);
	break;
 default:printf("parent process\n");
	printf("id=%d\n",id);
 }
}
