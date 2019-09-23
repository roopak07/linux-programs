#include<stdio.h>
void main()
{
int rev=0,n,mod,comp;
printf("Enter any number for reversing:");
scanf("%d",&n);
comp=n;
while(n%10)
 {
 mod=n%10;
 rev=rev*10+mod;
 n=n/10;
 }
printf("\nReverse of the number %d is:%d",comp,rev);
if(rev==comp)
 printf("\nEntered number is a palindrom\n");
else
 printf("\nEntered number is a not a palindrom\n");
}
