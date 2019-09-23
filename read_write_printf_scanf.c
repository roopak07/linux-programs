#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
char buf[13]="Hello world!\n";
/*write operation*/
int ret=write(1,buf,13); // acts like printf function
printf("ret=%d\n",ret);
if(ret>0)
printf("write succes, enter 13 charecters that you want to:\n");
else
printf("write error\n");
/*read operation*/
int ret1=read(0,buf,13);
printf("ret1=%d\n",ret1);
//buf[ret1]='\0';
for(int i=0;i<ret1;i++)
 {
 printf("%c",buf[i]);
 }
printf("\n");
if(ret1>0)
printf("read success\n");
else
printf("read fail\n");
}
