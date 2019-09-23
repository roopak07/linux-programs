#include <sys/mman.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include <sys/wait.h>
void main()
{
int stat;
char *ptr;
ptr=mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
*ptr=1;
int id=fork();
switch(id)
 {
 case -1: exit(5);
 case 0:printf("child processos started\n");
	(*ptr)++ ;
	exit(0);
default:wait(&stat);
	printf("parent processos\n");
	printf("*ptr=%d\n",*ptr);
 }
}
