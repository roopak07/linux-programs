#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/msg.h>
#include<sys/shm.h>

#define KEY 199120
char *shm;
struct sembuf smop;

void main()
{
int semid,shmid;
semid=semget(KEY,2,0);
shmid=shmget(KEY,512,0);
shm=shmat(shmid,NULL,0);
printf("Enter data to send:");
//scanf("%s\n",shm);
fgets(shm,256,stdin);
smop.sem_num=0;
smop.sem_op=1;
smop.sem_flg=0;
semop(semid,&smop,1); // unblock for server
smop.sem_num=1;
smop.sem_op=-1;
smop.sem_flg=0;
semop(semid,&smop,1);
printf("Recived data from clint:%s\n",shm+256);

}

