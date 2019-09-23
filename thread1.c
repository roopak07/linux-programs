#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void* abc(void* arg)
{
printf("New Thread\n");
}

int main()
{
pthread_t tid;
pthread_create(&tid,NULL,abc,NULL);
printf("Main thread\n");
pthread_join(tid,NULL);
return 0;
}

