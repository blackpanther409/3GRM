#include<stdio.h>

int fibanocci(int n)
{
	if(n==1)
	printf("1 ");
	
}

int main()
{
	int n;
	printf("Enter the number of fibanocci series numbers you need\n");
	scanf("%d",&n);
	printf("\n");
	fibanocci(n); 
	printf("\n"); 
	return 0;
}
