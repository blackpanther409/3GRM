#include<stdio.h>

long int digitsum(long int a)
{
	if(a==0)
	return 0;
	else
	return ((a%10)+digitsum(a/10));
} 

int main()
{
	long int a;
	printf("Enter a number to find the sum of the digits\n");
	scanf("%ld",&a);	
	printf("The sum of the digits is:%ld \n",digitsum(a));
	return 0;	
}

