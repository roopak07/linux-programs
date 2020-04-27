#include<unistd.h> // for alaram() system call
#include<signal.h> // for signal() system call
#include<stdio.h>
void my_handler(int signo);
void main()
{
 int ret;
 signal(14,my_handler);
 alarm(5); // it decrement value by 1 , when it reaches 0 it will send SIGALRM signal , i.e after 5 secs signal handler will be exicuted since SIGALRM signal number is 14 
 while(1){
 }
}
void my_handler(int signo)
{
 alarm(2); // for every 2 secs it will send SIGALRM signal , i.e for every 2 sec signal handler will be exicuted 
 printf("signal recived , signal number is:%d\n",signo);
}
 
