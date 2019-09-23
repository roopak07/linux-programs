#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
void main()
{
//char c[512];
//char *str;
char str[512];
//str=c;
printf("Enter data:");
scanf("%s\n",str);
int i=0;
strcpy((str+256),str);
printf("copied data is:");
printf("%s\n",(str+256));
while(*(str+256+i)!='\0')
{
if(*(str+256+i)>='a' && *(str+256+i)<='z')
{
(str+256)[i] = *(str+256+i)-32;
}
i++;
}
printf("%s\n",(str+256));
}


