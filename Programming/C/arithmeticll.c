#include<stdio.h>
#include<stdlib.h>
struct node
{
	data;
	struct node* next;

};
struct node *top1=NULL;
struct node *top2=NULL;
struct node *top3=NULL;
int main()
{
	char p;
	printf("Enter the first number\n");		
	for(int i=0;p!='\n';i++)
	{
		scanf("%c",&p);	
		push(p-48,&top1);
	}
	printf("Enter the second number\n");
	for(int i=0;p!='\n';i++)
	{
		scanf("%c",&top2);
		push(p-48,&top2);	
	}
	printf("Select one option \n1.add\n2.subtract\n3.multiply\n4.divide\n");
	addition();
return 0;
}

void push(int x,struct node **top)
{
	struct node *tmp=malloc(sizeof(struct node));	
	tmp->data=x;
	tmp->next=*top->next;
	*top=tmp;
}

int pop(struct node **top)
{
	int x;	
	if(top==NULL)
	return 0;
	else
	{
		x=*top->data;		
		*top=*top->next;
	}

}

void addition()
{
	int a,b,c;
	a=pop(&top1);
	b=pop(&top2);
	

}

void subtract()
{



}
