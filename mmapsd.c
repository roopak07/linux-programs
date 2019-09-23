#include <sys/mman.h> //mmap
#include<sys/stat.h> // fstat 
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
struct stat buf; // inode object is present is "stat" , buf is the variable for the structure
void main()
{
char *srptr,*dtptr;
int srcfd=open("source.txt",O_RDWR);
printf("srcfd:%d\n",srcfd);
fstat(srcfd,&buf);// initially buf will be empty ,once this line exicutes indoes objects are copiedinto the buf
printf("%zu \n",buf.st_size); //st_size is of type "off_t" , formate specifier for "off_t" is "zu"  
srptr=mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,srcfd,0);
//close(srcfd);
int dstfd=open("dest1.txt",O_RDWR|O_CREAT,0640);
ftruncate(dstfd,buf.st_size); 
printf("dstfd:%d\n",dstfd);
dtptr=mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,dstfd,0);
memcpy(dtptr,srptr,buf.st_size);
}
