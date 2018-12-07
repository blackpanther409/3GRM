#include<stdio.h>
int prime(int a)
{
	int c=0;
	for(int i=2;i<a;i++)
	{
		if(a%i==0)
		{
			c++;
			break;
		}
	}
	if(c==0 || a==2)
	return 1;
	else
	return 0;
}

void primefactor(int num,int i)
{
	if(i==2)
	{
		printf("2\n");
		return;
	}
	if(num%i==0)
	{
		if(prime(i))
		{
			printf("%d\n",i);
			num=num/i;
			i++;
		}
		
	}
	i--;
	primefactor(num,i);
	
}
int main()
{
	int num,i;
	printf("Enter the number to find its primefactors\n");
	scanf("%d",&num);
	i=num;
	printf("\n");
	primefactor(num,i);
	return 0;
}
