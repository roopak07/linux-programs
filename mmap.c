#include <sys/mman.h> //mmap
#include<sys/stat.h> // fstat 
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
struct stat buf; // inode object is present is "stat" , buf is the variable for the structure
void main()
{
char *ptr;
int fd=open("source.txt",O_RDWR);
printf("fd:%d\n",fd);
fstat(fd,&buf);// initially buf will be empty ,once this line exicutes indoes objects are copiedinto the buf
printf("%zu \n",buf.st_size); //st_size is of type "off_t" , formate specifier for "off_t" is "zu"  
ptr=mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
for(int i=0;i<buf.st_size;i++)
 { 
 printf("%c",ptr[i]);
 }
printf("\n");
}
