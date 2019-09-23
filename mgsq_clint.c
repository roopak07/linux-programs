#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>


#define MY_KEY 19920809
#define MSG_LEN 256
#define SRV_MSG_TYPE 1

int main()
{
	int msgid;
	int msgLen, cliMsgType;
	char rxmsg[MSG_LEN];
	char txmsg[MSG_LEN];
	int *msgHdr = (int *)txmsg;
	
	msgid = msgget(MY_KEY,0);
	printf("message que id:%d\n",msgid);
	if(msgid < 0)
	{
		printf("Could not open the message queue\n");
		return 1;
	}
	printf("Client: Enter some request message to send to server %d\n",msgid);
	scanf("%s",txmsg+8);
	//fgets(txmsg+8,MSG_LEN,stdin);
	msgHdr[0] = SRV_MSG_TYPE;
	/***User process Id as client message type **/
	cliMsgType = getpid();
	msgHdr[1] = cliMsgType;
	printf("%s\n",txmsg+8);
	int ns=msgsnd(msgid,txmsg,4+4+strlen(txmsg+8)+1,0);
	if(ns<0)
 	printf("Failed to send message\n");
	else
 	printf("message sent sucessfull\n");

	/*msgsnd(mqId, txmsg, strlen(txmsg+8)+8,0);
	
	printf("Client: sent given request message to server\n");
	msgLen = msgrcv(mqId, rxmsg, MSG_LEN, cliMsgType, 0);
	printf("Client: Follwing is the response message from server\n");
	puts(rxmsg+4); */
}
