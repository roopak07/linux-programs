#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER; // initally mutex will be in Unlock state
int count=0;
void *abc(void *arg)
{
	pthread_mutex_lock(&lock);
	count = count+1;
	printf("Thread %d started\n",count);
	for(unsigned long i=0;i<=50000;i++);
	printf("Thread %d end\n",count);
	//sleep(1);
	pthread_mutex_unlock(&lock);
}

void main()
{
pthread_t tid[5];
for(int i=0;i<5;i++)
{
pthread_create(&tid[i],NULL,abc,&i); //passing address of i as an argument to new thread, pthread_create will return 0 if call is sucess ,any other value if call fails
}
for(int i=0;i<5;i++)// waits untill all threads complets there exicution
{
pthread_join(tid[i],NULL);
}
pthread_mutex_destroy(&lock); 
}
