#include<stdio.h>
#include<sys/stat.h> // for stat, read,open
#include<fcntl.h> // for stat, read,open
#include<sys/types.h> // for stat, read,open
#include<unistd.h> // for write
#include<string.h>

struct stat buf;
char wrtxt[100],retxt[100];

void main()
{
// opening or creating a file
int fd=open("mini.txt",O_RDWR|O_CREAT,0640);
printf("fd=%d\n",fd);
 if(fd>0)
 {
 printf("file created\n");
 }
 else
 {
 printf("file creation error");
 }
printf("enter data:\n");
fgets(wrtxt,100,stdin);
//scanf("%s",wrtxt); // if we use scanf it will take space as null charecter
// writing data to a file
int wr=write(fd,wrtxt,strlen(wrtxt));
printf("wr=%d\n",wr);
 if(wr>0)
 {
 printf("write sucess\n");
 }
 else
 {
 printf("write fail\n");
 }
//close(fd); 

//read operation
fd=open("mini.txt",O_RDONLY); 
printf("fd for open:%d \n",fd);
 if(fd>0)
 printf("file open success \n");
 else
 printf("file open error \n");
int re=read(fd,retxt,strlen(wrtxt));
printf("re=%d\n",re); 
if(re>0)
 printf("read sucess\n");
else
 printf("read failed\n");
printf("entered data is:%s\n",retxt);
fstat(fd,&buf);
/*      
               dev_t     st_dev;         // ID of device containing file 
               ino_t     st_ino;         // Inode number 
               mode_t    st_mode;        // File type and mode 
               nlink_t   st_nlink;       // Number of hard links
               uid_t     st_uid;         // User ID of owner
               gid_t     st_gid;         // Group ID of owner
               dev_t     st_rdev;        // Device ID (if special file)
               off_t     st_size;        // Total size, in bytes
               blksize_t st_blksize;     // Block size for filesystem I/O
               blkcnt_t  st_blocks;      // Number of 512B blocks allocated
*/
printf("id of device(st_dev):%ld\n",(buf.st_dev));
printf("inode number(st_ino):%ld\n",buf.st_ino);
printf("mode of file(st_mode):%hu \n",buf.st_mode);
printf("number ofhard links(st_nlink):%ld\n",(buf.st_nlink));
printf("user id of the owner(buf.st_uid):%d \n",buf.st_uid);
printf("group id of the owner(st_gid):%d \n",buf.st_gid);
printf("device id(st_rdev):%ld\n",buf.st_rdev);
printf("size of file(inode object size, buf.st_size):%zu \n",buf.st_size);
printf("block size for filesystem I/O(st_blksize):%ld\n",buf.st_blksize);
printf("Number of 512B blocks allaocted(st_blocks):%ld\n",buf.st_blocks);
}
