#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/wait.h>

int x=10;
void main()
{
int stat,id;
id=fork();
if(id == 0)
 {
 x=20;
 printf("child processos\n");
 exit(5);
 }
id=wait(&stat);
printf("Exit status:%d\n",WEXITSTATUS(stat));
printf("x=%d\n",x);
}
