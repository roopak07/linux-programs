#include<stdio.h>
#include<signal.h>
void myhandler(int signo)
{
	printf("I am the signal Handler and my signal no is:%d \n",signo);
	sleep(1);
}
void main()
{
	printf("Signal Handler test started \n");
	signal(SIGINT,myhandler);
	while(1)
	{
		printf("Inside while loop \n");
		sleep(1);
	}
}
