#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/shm.h>
#include<stdlib.h>

#define KEY 19920809
char *shm;
void main()
{
int shmid=shmget(KEY,20,0);
printf("shmid=%d\n",shmid);

if(shmid>0)
 {
 printf("shared memeory is created\n");
 }
else
 {
 printf("shared memeory error\n");
 }
shm=shmat(shmid,NULL,0);
printf("Enter data to transmit:");
scanf("%s",shm);
printf("data entered in shm = %s \n",shm);
//printf("*shm=%d\n",*shm);

*shm= 'V';
printf("data after toggling in clint: %s\n",shm);
}

