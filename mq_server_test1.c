#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<fcntl.h>
#include<ctype.h>

#define KEY 19920809
#define srvmsgtype 1

char rxmsg[20],txmsg[20];
int *msgheader=(int*)txmsg;
void main()
{
int nr;

int msqid=msgget(KEY,IPC_CREAT|0660);
printf("message id of server:%d\n",msqid);

if(msqid<0)
 printf("faild to creat server\n");
else
{
 printf("server ceated \n");
 printf("waiting for the responce from clint \n");
 nr=msgrcv(msqid,&msgheader,20,srvmsgtype,0); // blocking call
}

if(nr==-1)
{ 
perror("msgrcv");
}
else
{
 printf("Recived message from clint of size:%d\n",nr);
 puts(rxmsg);
 for(int i=0;i<nr;i++)
 {
  rxmsg[i]=toupper(rxmsg[i]);
 }
 printf("recived message from clint:%s \n",rxmsg);
}
}

