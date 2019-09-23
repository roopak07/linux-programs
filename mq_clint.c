#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#define KEY 19920809
#define srvmsgtype 1

void main()
{
char rxmsg[20],txmsg[20];
int *msgheader = (int*)txmsg;
int msgid=msgget(KEY,0);
printf("clint msgid:%d\n",msgid);
if(msgid<0)
 printf("could not open message queue\n");
else{
printf("message queue is opened\n");
 printf("Enter data to transmit:\n");
//scanf("%s",&(txmsg+8));
fgets(txmsg+8,20,stdin);
}
msgheader[0]=srvmsgtype;
msgheader[1]=getpid();
int ns=msgsnd(msgid,&txmsg,4+4+strlen(txmsg+8)+1,0);
printf("/*************complet details************/\n");
printf("txmsg+8 :%s\n",txmsg+8);
printf("msgheader[0] :%d\n",msgheader[0]);
printf("msgheader[1] :%d\n",msgheader[1]);
printf("ns :%d\n",ns);
if(ns<0)
 printf("Failed to send message\n");
else
 printf("message sent sucessfull\n");
printf("transmited data:%s \n",txmsg+8);
}

