#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void *abc(void *arg)
{
	int *val = (int *)arg; // converting arg to intiger pointer, local pointer variable
	int b=*val+1; // local variable , 
	printf("value=%d\n",b);
	sleep(1);
}

void main()
{
pthread_t tid[5];
int a=2;
for(int i=0;i<5;i++)
{
tid[i]=pthread_self(); //getting thread id
printf("thread id_%d:%lu \n",i,tid[i]);
pthread_create(&tid[i],NULL,abc,&a); //passing address of val as an argument to new thread 
pthread_join(tid[i],NULL); // wait until each thread complets its exicution 
}
}
