#include<stdio.h>
#include<stdlib.h>
struct Tnode
{
	int data;
	struct Tnode *lcptr;
	struct Tnode *rcptr;
};
struct Tnode *rptr=NULL;
void postorder(struct Tnode *ptr);
void insert(int x);
void insert(int x)
{
   	struct Tnode *tmp=malloc(sizeof(struct Tnode));
	tmp->data=x;
	tmp->lcptr=NULL;
   	tmp->rcptr=NULL;
   if(rptr==NULL)
	{	
		rptr=tmp;
	}
	else
	{
		struct Tnode *ptr=rptr;
		struct Tnode *pptr=NULL;
      		while(ptr!=NULL)
		{
			pptr=ptr;
         		if(x<ptr->data)
			{
				ptr=ptr->lcptr;	
			}
			else
			{
				ptr=ptr->rcptr;
			}
		}
		if(x<pptr->data)
			pptr->lcptr=tmp;
		else
			pptr->rcptr=tmp;	
	}	

}

void postorder(struct Tnode *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->lcptr);
		postorder(ptr->rcptr);
		printf("%d ",ptr->data);
	}
}

int main()
{
	int x,p;
	printf("Enter the number of elements are present in your preorder\n");
	scanf("%d",&p);
	printf("Enter the preorder of the elements to construct BST\n");
	for(int i=0;i<p;i++) 
	{
		scanf("%d",&x);	
		insert(x);
	}
	postorder(rptr);
	printf("\n");

	return 0;
}
