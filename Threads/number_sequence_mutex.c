#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
pthread_mutex_t ml=PTHREAD_MUTEX_INITIALIZER;
int global=1,n=0;
void *tfun(void *arg)
{
 pthread_mutex_lock(&ml);
 printf("\nthread %d is Running\n",++n);
 for(int i=0;i<10;i++)
 {
  printf("%d ",global++);
 }
  printf("\n");
 pthread_mutex_unlock(&ml);
}

void main()
{
 pthread_t tid[5];
 for(int i=0;i<5;i++)
 {
  pthread_create(&tid[i],NULL,tfun,&i);
 }
for(int i=0;i<5;i++)
 {
  pthread_join(tid[i],NULL);
 }
 pthread_mutex_destroy(&ml);
}
