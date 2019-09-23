
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#define KEY 19920809
#define srvmsgtype 1

char rxmsg[20],txmsg[20];
int *msgheader = (int*)txmsg;
void main()
{
int msgid=msgget(KEY,0);
printf("clint msgid:%d\n",msgid);

if(msgid<0)
 printf("could not open message queue\n");
else{
printf("message queue is opened\n");

printf("Enter data to transmit:\n");
//scanf("%s",&(txmsg+8));
fgets(txmsg,20,stdin);
}
msgheader[0]=srvmsgtype;
msgheader[1]=getpid();
int ns=msgsnd(msgid,(int*)&msgheader,strlen(txmsg),0);
if(ns<0)
 printf("Failed to send message\n");
else
 printf("message sent sucessfull\n");
printf("transmited data:%s \n",txmsg);
}

