#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *set1=NULL;
struct node *set2=NULL;
struct node *universal=NULL;
int main()
{
	int c;
	printf("Select any option\n1.union\n2.intersection\n3.complement\n");
	scanf("%d,&c");	
	switch(c)
	{
		case 1:uni();goto A;	
		case 2:inter();goto A;
		case 3:compliment();goto A;
	
	}

return 0;
}

void uni()
{
	printf("Enter the elements of first set\n");
	int p;
	for(int i=0;p	

}

