#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<fcntl.h>
#include<ctype.h>

#define KEY 19920809
#define srvmsgtype 1

void main()
{
int nr;
char rxmsg[20],txmsg[20];
int msgid=msgget(KEY,IPC_CREAT|0666);
printf("message id of server:%d\n",msgid);
if(msgid<0)
 printf("faild to creat server\n");
else
{
 printf("server ceated \n");
printf("rxmsg:%s\n txmsg:%s\n",rxmsg+8,txmsg+8);
printf("waiting for the responce from clint \n");
nr=msgrcv(msgid,&rxmsg,20,srvmsgtype,0); // blocking call
}

if(nr==-1)
{ 
perror("msgrcv");
}
else
{
printf("Recived message from clint of size:%d\n",nr);
puts(rxmsg+8);
for(int i=0;i<nr;i++)
 {
 rxmsg[i+8]=toupper(rxmsg[i+8]);
 }
 printf("recived message from clint:%s \n",rxmsg+8);
}
}

