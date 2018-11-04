#include<stdio.h>
#include<stdlib.h>
struct node 
{ 
	int data;
	struct node *nptr; 
};
struct node *fptr;
struct node *rptr;
struct node *hptr;
void Enqueue();
void Dequeue();
void print();
void isfull();
void isempty();
void search();
int main()
{
	int i;
	A:
	printf("Select any one option\n1.enqueue\n2.dequeue\n3.print\n4.isfull\n5.isempty\n6.search\n");
	scanf("%d",&i);
	switch(i)
	{
	  case 1:Enqueue();goto A;break;
	  case 2:Dequeue();goto A;break;
	  case 3:print();goto A;break;
	  case 4:isfull();goto A;break;
	  case 5:isempty();goto A;break;
	  case 6:search();goto A;break;
	}
return 0;
}

void Enqueue()
{	int x;
    printf("Enter the element to be  enqueued\n");
    scanf("%d",&x);
	struct node*temp=malloc(sizeof(struct node));
	struct node*thptr=hptr;
	if(temp!=NULL)
    {	
        if(hptr!=NULL)
        {	while((thptr->nptr)!=NULL)
        	{
       		 	thptr=thptr->nptr;
        	}
        	thptr->nptr=temp;
    		temp->data=x;
    		temp->nptr=NULL;
    	}
    	else
    	{	hptr=temp;
    		temp->data=x;
    		temp->nptr=NULL;
    	}
    }  	
    else 
    printf("Sorry cannot enqueue as the memory is not available\n");
}

void Dequeue()
{	int x;
	if(hptr==NULL)
	printf("Sorry nothing to dequeue out\n");
	else
	{
		x=hptr->data;
		hptr=hptr->nptr;
		 
		printf("The deleted number is %d\n",x);
	}
}

void print()
{   if(hptr!=NULL)
  {
	struct node *ptr=hptr;
	printf("The elements of the queue are : ");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);	
		ptr=ptr->nptr;
	}
	printf("\n");
  }	
  else
  printf("Nothing to print\n");
}

void isfull()
{
	struct node*temp=malloc(sizeof(struct node));
	if(temp==NULL)
	printf("The queue is full\n");
	else
	printf("The queue is not full\n");
}

void isempty()
{
	if(hptr==NULL)
	printf("The stack is empty\n");
	else
	printf("The stack is not empty\n");
}
void search()
{	int x,c=0;
if(hptr!=NULL)
 {	struct node*ptr=hptr;
	printf("Enter the element to be searched\n");
	scanf("%d",&x);
	while(ptr!=NULL)
	{
		if(ptr->data==x)
		c++;
		ptr=ptr->nptr;
	}
	if(c!=0)
	printf("The element is present in the queue\n");
	else
	printf("The element is not present in the queue\n");
 }
 else
 printf("Sorry no elements in queue,cannot search\n");
}















