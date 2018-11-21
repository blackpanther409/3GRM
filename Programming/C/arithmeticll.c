#include<stdio.h>
#include<stdlib.h>
int c=0;
struct node
{
	char data;
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
	char p[100];
	int c;
	B:
	printf("Enter the first number\n");	
	scanf("%s",p);	
	for(int i=0;p[i]!='\n';i++)
	{	
		push(p[i]-48,&top1);
	}
	printf("Enter the second number\n");
	scanf("%s",p);
	for(int i=0;p[i]!='\n';i++)
	{
		push(p[i]-48,&top2);	
	}
	 
	A:
	printf("Select one option \n1.add\n2.subtract\n3.give another set of numbers\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:addition();top3=NULL;goto A;break;
		//case 2:subtraction();top3=NULL;goto A;break;		
		case 3:goto B;break;
	}
	
return 0;
}

void push(int x,struct node **top)
{
	struct node *tmp=malloc(sizeof(struct node));	
	tmp->data=x;
	if((*top)!=NULL)
	{	
		tmp->next=(*top)->next;
	}	
	(*top)=tmp;
}

int pop(struct node **top)
{
	int x;	
	if((*top)==NULL)
	return 0;
	else
	{
		x=(*top)->data;		
		(*top)=(*top)->next;
		return x;
	}

}

void addition()
{
	int a,b;
	struct node *top=top3;
	struct node *thp1=top1;
	struct node *thp2=top2;
	while(thp1!=NULL || thp2!=NULL) 
	{	
		a=pop(&top1);
		b=pop(&top2);
		push(((a+b)%10),&top3);
		c=(a+b+c)/10;
		thp1=thp1->next;
		thp2=thp2->next;
	}
	printf("\n\n");
	while(top!=NULL)
	{
		printf("%d",top->data);
		top=top->next;
	}
	printf("\n\n");
}

//void subtract()
//{
	



//}








