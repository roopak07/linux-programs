
// C Program for Message Queue (Writer Process) 
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include<string.h>
  
// structure for message queue 
struct mesg_buffer { 
    long mesg_type; 
    char mesg_text[100]; 
} message; 
  
int main() 
{ 
    key_t key; 
    int msgid; 
  
    // ftok to generate unique key 
    key = ftok("progfile", 65); 
  
    // msgget creates a message queue 
    // and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT);
	printf("clint msgid:%d\n",msgid); 
    message.mesg_type = 1; 
  
    printf("Write Data : "); 
    fgets(message.mesg_text,100,stdin); 
  
    // msgsnd to send message 
    int cm=msgsnd(msgid, &message, sizeof(message), 0); 

	printf("*****complet data*****\n");
	printf("msgid:%d\n",msgid);
	printf("clint message:%d\n",cm);
  
    // display the message 
    printf("Data send is : %s \n", message.mesg_text); 
  
    return 0; 
} 

