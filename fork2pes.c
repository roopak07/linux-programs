#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
void main()
{
int stat,chid1,chid2;
chid1=fork();
printf("id of first child:%d\n",chid1);
if(chid1==0)
 {
 printf("child process 1 \n");
 sleep(60);
 exit(5);
 }
chid2=fork();
printf("id of second child:%d\n",chid2);
if(chid2==0)
 {
 printf("child process 2 \n");
 sleep(60);
 exit(4);
 }

chid1=wait(&stat); 
printf("chid1:%d	exit status:%d\n",chid1,WEXITSTATUS(stat));
chid2=wait(&stat); 
printf("chid2:%d	exit status:%d\n",chid2,WEXITSTATUS(stat));

}
