#include<stdio.h>
#include<string.h> // for strlen function
#include<unistd.h> // for close,open,read,write system call
#include<fcntl.h> // for O_RDONLY,O_WRONLY,O_RDWR etc macros
void main()
{
	int fd = open("file.txt",O_WRONLY|O_CREAT,0777);
	printf("fd of the file is %d\n",fd);
	if(fd>0)
		printf("file open sucess \n");
	else
		printf("file open error \n");
	char buf[100];
	printf("Enter anything to write in the file:\n");
	fgets(buf,100,stdin);
	int wc=write(fd,buf,strlen(buf));
	if(wc>0)
		printf("Write sucess and no:of chacters written into the file is %d\n",wc);
	else
		printf("Write error \n");
	close(fd);
	fd = open("file.txt",O_RDONLY|O_CREAT,0777);
	printf("fd of the file is %d\n",fd);
	if(fd>0)
		printf("file open sucess \n");
	else
		printf("file open error \n");
	int rc=read(fd,buf,strlen(buf));
	if(rc>0)
		printf("Read sucess and number of characters read from file is %d\n",rc);
	else
		printf("Read error \n");
	printf("Data in the file is:%s \n",buf);	
}
