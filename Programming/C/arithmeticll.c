#include<stdio.h>
#include<stdlib.h>
int c=0;
struct node
{
	data;
	struct node* next;

};
struct node *top1=NULL;
struct node *top2=NULL;
struct node *top3=NULL;
void push(int x,struct node **top);
int pop(struct node **top);
void addition();
void subtract();
int main()
{
	char p;
	B:
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
	A:
	printf("Select one option \n1.add\n2.subtract\n3.multiply\n4.divide\n5.give another set of numbers\n");
	switch(c)
	{
		case 1:addition();top3=NULL;goto A;break;
		case 2:subtraction();top3=NULL;goto A;break;		
		case 3:multiplcation();top3=NULL;goto A;break; 
		case 4:division();top3=NULL;goto A;break;
		case 5:goto B;break;
	}
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
		return x;
	}

}

void addition()
{
	int a,b;
	while(top1!=NULL || top2!=NULL) 
	{	
		a=pop(&top1);
		b=pop(&top2);
		push(((a+b)%10),&top3);
		c=(a+b)/10;
	}
	
	
}

//void subtract()
//{
	



//}







}
