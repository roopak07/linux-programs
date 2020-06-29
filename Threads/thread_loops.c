#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
/* Threads will run parallely one after the other, main function is like 1st thread , abc is 2nd thread*/
void *abc(void *arg)
{
	for(int p=0;p<10;p++)
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
pthread_create(&tid,NULL,abc,NULL); 
for(int i=0;i<10;i++)
{
	printf("i=%d\n",i);
	sleep(1);
}
pthread_join(tid,NULL);
}
