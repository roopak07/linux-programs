#include<signal.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
int asci_to_int(char *str);
void main(int argc,char *argv[])
{
 int pid,signo,ret;
 if(argc!=3) // we need to pass only 3 arguments i.e file name , signal number and pid
 {
	printf("Invalid operation \n ./kill -<signo> <pid> \n");
	exit(1);
 }
 pid = asci_to_int(argv[2]); // argv[2] will store pid , since 2nd argument is pid
 signo = asci_to_int(&argv[1][1]); // since argv[1][0] = '-' , argv[1][1] = 'signo'
 ret=kill(pid,signo);
 if(ret>=0)
	printf("process with %d pid is killed\n",pid);
 else
	printf("Kill error \n");
}

int asci_to_int(char *str)
{
 int num=0,temp,i;
 for(i=0;str[i]!='\0';i++)
 {
  temp = str[i] - 48;// if str[1] = 1 ; asci of '1' is 49 , so 49-48 = 1(digital value) , asci value of 0 is 48
  num = temp + num*10;
 }
 return num;
}
