#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/wait.h>

int x=10,a=0;

void main()
{
if(a == 0)
 {
 x=20;
 printf("child processos\n");
 }
printf("x=%d\n",x);
}
