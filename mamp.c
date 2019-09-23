#include <sys/mman.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
char *ptr;
int fd=open("abc4.txt",O_RDWR);
printf("fd:%d\n",fd);
ptr=mmap(NULL,9,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
for(int i=0;i<9;i++)
 { 
 printf("%c",ptr[i]);
 }
printf("\n");
}
