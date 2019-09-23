#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
void main()
{
char buf[10];
int fds[2];
pipe(fds);
int id=fork();
printf("id=%d\n",id);
if(id==0)
 {
int ret=read(fds[0],buf,20);
printf("ret=%d \n",ret);
buf[ret]='\0';
printf("%s \n",buf);
 }
else
 {
 printf("enter data:\n");
 scanf("%s",buf);
 write(fds[1],buf,strlen(buf));
 }
}
