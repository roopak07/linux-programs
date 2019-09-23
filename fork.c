#include<stdio.h>
#include<unistd.h>

void main()
{
printf("befor fork\n");
int id=fork();
printf("after fork\n");
printf("id=%d\n",id);
}
