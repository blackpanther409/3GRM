#include<stdio.h>
#include<stdlib.h>
struct Tnode
{
	struct Tnode *lcptr;
	long int data;
	long int tele;
	int height;
   struct Tnode *rcptr;
}*rptr=NULL;
struct Tnode* insert(struct Tnode *ptr,long int x);
void updateheight(struct Tnode *ptr);
int findheight(struct Tnode *ptr);
struct Tnode* RotateRight(struct Tnode *ptr);
struct Tnode* RotateLeft(struct Tnode *ptr);
struct Tnode* RotateRightLeft(struct Tnode *ptr);
struct Tnode* RotateLeftRight(struct Tnode *ptr);
void search();
void print(struct Tnode *ptr)
{
	if(ptr!=NULL)
	{
		print(ptr->lcptr);
		printf("adhar:%ld \ntelephone no:%ld\nheight:%d\nbalancing factor:%d\n",ptr->data,ptr->tele,ptr->height,findheight(ptr->lcptr)-findheight(ptr->rcptr));
		print(ptr->rcptr);
	}
}
void main()
{
	int i;
	long int x;
	A:
	printf("Select anyone option\n1.Insert\n2.search by adhar\n3.print\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:printf("Enter the adhar number\n");
		scanf("%ld",&x);
		rptr=insert(rptr,x);goto A;
		case 2:search();goto A;
		case 3:print(rptr);goto A;

	}
	 
}
struct Tnode* insert(struct Tnode *ptr,long int x)
{  
	if(ptr==NULL)
   {
		
	   	ptr=malloc(sizeof(struct Tnode));
		
		printf("Enter the telephone number\n");
		scanf("%ld",&ptr->tele);
		ptr->data=x;	
		ptr->lcptr=NULL;
		ptr->rcptr=NULL;
		ptr->height=0;
	}
	else
	{
		if(x<ptr->data)
		{
			ptr->lcptr=insert(ptr->lcptr,x);
			if(findheight(ptr->lcptr)-findheight(ptr->rcptr)==2 ||findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2)
			{
				
				if(x<ptr->lcptr->data)
					ptr=RotateRight(ptr);
				else
					ptr=RotateLeftRight(ptr);
			} 
		}
		else
		{
			ptr->rcptr=insert(ptr->rcptr,x);
			if(findheight(ptr->lcptr)-findheight(ptr->rcptr)==2 ||findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2)
			{
				if(x>ptr->rcptr->data)
					ptr=RotateLeft(ptr);
				else
					ptr=RotateRightLeft(ptr);
			} 
		}		
	}
	updateheight(ptr);
   return ptr;
}
int findheight(struct Tnode *ptr)
{
	int h1,h2;
	if(ptr==NULL)
	{
		return -1;
	}
	else
	{
 		h1 = findheight(ptr->lcptr);
		h2= findheight(ptr->rcptr);
		if(h1<h2)
			return h2+1;
		else
			return h1+1;
	}
}
void updateheight(struct Tnode *ptr)
{	
   
   int h1,h2;
	if(ptr->lcptr==NULL)
	{
		h1=-1;
	}
	else
		h1=ptr->lcptr->height;
	if(ptr->rcptr==NULL)
	{
		h2=-1;
	}
	else
		h2=ptr->rcptr->height;
	if(h1<h2)
		ptr->height=h2+1;		
	else
		ptr->height=h1+1;
}
struct Tnode* RotateRight(struct Tnode *ptr)
{
	struct Tnode *jptr=ptr;
	struct Tnode *kptr=ptr->lcptr;
	jptr->lcptr=kptr->rcptr;
	kptr->rcptr=jptr;
	updateheight(jptr);
	updateheight(kptr);
	return kptr;
}
struct Tnode* RotateLeft(struct Tnode *ptr)
{
	struct Tnode *jptr=ptr;
	struct Tnode *kptr=ptr->rcptr;
	jptr->rcptr=kptr->lcptr;
	kptr->lcptr=jptr;
	updateheight(jptr);
	updateheight(kptr);
	return kptr;
}
struct Tnode* RotateLeftRight(struct Tnode *ptr)
{
	struct Tnode *jptr=ptr;
	struct Tnode *kptr=ptr->lcptr;
	ptr->lcptr=RotateLeft(kptr);
	return(RotateRight(jptr));
}
struct Tnode* RotateRightLeft(struct Tnode *ptr)
{
	struct Tnode *jptr=ptr;
	struct Tnode *kptr=ptr->rcptr;
	ptr->rcptr=RotateRight(kptr);
	return(RotateLeft(jptr));
}

void search()
{
	long int x;
	printf("Enter the adhar number\n");
	scanf("%ld",&x);
	struct Tnode *thptr=rptr;
	while(thptr!=NULL)
	{
		if(x<thptr->data)
		thptr=thptr->lcptr;
		else if(x>thptr->data)
		thptr=thptr->rcptr;	
		else
		{
			printf("The adhar number you are searching for is here\nadhar no:%ld\ntelephone no:%ld\nheight:%d\nbalancing factor:%d\n",thptr->data,thptr->tele,thptr->height,findheight(thptr->lcptr)-findheight(thptr->rcptr));
			break;
		}		
	}

}




