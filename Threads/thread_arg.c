#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void *abc(void *arg)
{
	int *add = (int *)arg; // converting arg to intiger pointer
	printf("value of val=%d\n",*add);
	for(int p=0;p<=20;p++)
	{
	printf("p=%d\n",p);
	sleep(1); // try without loops
	}
}

void main()
{
pthread_t tid;
tid=pthread_self(); //getting thread id
printf("thread id:%lu \n",tid);
int val=10;
pthread_create(&tid,NULL,abc,&val); //passing address of val as an argument to new thread 
for(int i=0;i<=10;i++)
{
	printf("i=%d\n",i);
	sleep(1);
}
pthread_join(tid,NULL);
}
