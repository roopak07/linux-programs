#include <sys/mman.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include <sys/wait.h>
#include <sys/stat.h> 

void main()
{
char *addr;
int fd=shm_open("/demo_shm",O_RDWR|O_CREAT,0640);
printf("fd:%d\n",fd);
ftruncate(fd,10);
addr = mmap(NULL,10,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
memcpy(addr,"Hello",5);
}
