#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/msg.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<sys/ipc.h>

#define KEY 199120
char *shm;
struct sembuf smop;

void main()
{
int semid,shmid,i=0;
semid=semget(KEY,2,IPC_CREAT|0640); // creating semaphore object and semaphore sets
semctl(semid,0,SETVAL,0); // assigining 0 to index 0 counter
semctl(semid,1,SETVAL,0); // assigining 0 to index 1 counter
shmid=shmget(KEY,512,IPC_CREAT|0640); //creating shared memeory segment
shm=shmat(shmid,NULL,0); //getting base address of shared memory segment
smop.sem_num=0; // 1st semaphore counter index=0
smop.sem_op=-1;// decrementing by 1
smop.sem_flg=0; 
semop(semid,&smop,1); // block
printf("Recoved data from clint whic is stored in shm:");
printf("%s\n",shm); // print data present in smared memory
strcpy((shm+256),shm); // copy data from first half of shared memoy to second half of shared memeory
printf("copied data to shm+256 th location:");
printf("%s\n",shm+256);
/* logic for converting lower case to upper case */
while(*(shm+256+i)!='\0')
 {
 if(*(shm+256+i)>='a' && *(shm+256+i)<='z')
  {
  (shm+256)[i]=*(shm+256+i)-32;
  }
  i++;
 }
smop.sem_num=1; // 2nd semaphore (index 1)
smop.sem_op=1; // increamenting by 1
smop.sem_flg=0;
semop(semid,&smop,1); // unblock for clint
}


