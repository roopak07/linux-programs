#include <sys/mman.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct stat buf;
void main()
{
char *addr;
int fd=shm_open("/demo_shm",O_RDWR,0);
fstat(fd,&buf);
addr = mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
for(int i=0;i<buf.st_size;i++)
 {
 printf("%c",addr[i]); // we can also use *(addr+i)
 }
printf("\n");
}
