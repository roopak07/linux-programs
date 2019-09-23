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
int shmid=shmget(KEY,20,IPC_CREAT|0647);
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
//printf("data present in shm or recived data from clint=%s\n",shm);
while(*shm!='V');
 {
 sleep(1);
 }
printf("recived data after toggling: %s\n",shm);
}

