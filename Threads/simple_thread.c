#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void *abc(void *arg)
{
	printf("New Thread\n");
}

void main()
{
pthread_t tid; // creating thread id
pthread_create(&tid,NULL,abc,NULL);
printf("main thread\n");
pthread_join(tid,NULL); // wait untill child thread complets the process
}
