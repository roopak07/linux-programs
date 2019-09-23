#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void* abc(void *arg) // intializing arg as a void pointer,we are collecting "Hello" in arg 
{
char *str=(char*)arg; // (char *)arg will return a address ,we are applying * to the adress ,it will point to charcters ,since we diclearead str as charcter pointer type,
printf("New Thread\n");
printf("data from main thread is:%s\n",str);
}

int main()
{
pthread_t tid; // defining thread variable
tid=pthread_self(); // getting thread id
printf("thread id: %lu\n",tid);// printing thread id, thred id is of type long unsigned (%lu)
int p=pthread_create(&tid,NULL,abc,"Hello"); //creating a thread and calling "abc" function, we are sending "Hello" to abc function 
printf("Return value of pthread_creat : %d\n",p);// value of p will be 0 if thread is created sucessfully, if we get any other value rathaer than 0 ,then it indicates that thread is not creted or thread error
printf("Main thread\n");
pthread_join(tid,NULL); // its a blocking call ,waits untill New thread complets its task
return 0; // returning inteiger value 0 since main function is of type intiger function
}

