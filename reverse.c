#include<stdio.h>
void main()
{
int rev=0,n,mod;
printf("Enter any number for reversing:");
scanf("%d",&n);
while(n%10)
 {
  mod=n%10;
  rev=rev*10+mod;
  n=n/10;
 }
printf("\nReverse of the number: %d\n", rev);
}
