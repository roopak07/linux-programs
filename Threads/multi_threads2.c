#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void *abc(void *arg)
{
	int *add = (int *)arg; // converting arg to intiger pointer
	printf("Thread no=%d\n",*add);
	sleep(1);
}

void main()
{
pthread_t tid[5];
for(int i=0;i<5;i++)
{
tid[i]=pthread_self(); //getting thread id
printf("thread id_%d:%lu \n",i,tid[i]);
pthread_create(&tid[i],NULL,abc,&i); //passing address of val as an argument to new thread 
//pthread_join(tid[i],NULL); // wait until each thread complets its exicution 
}
for(int i=0;i<5;i++)// waits untill all threads complets there exicution
{
pthread_join(tid[i],NULL);
}
}
