#include<stdio.h>
#include<string.h>
void main()
{
char a[100],b[100];
printf("\nEnter charecters:");
gets(a);

printf("\nEntered string is:");
puts(a);

strcpy(b,a);
strrev(a);
printf("Reverse of the sting is:");
puts(a);
if( strcmp(b,a)==0 )
 printf("Entered string is palindrom");
else
 printf("Entered string is not a palindrom");

}
