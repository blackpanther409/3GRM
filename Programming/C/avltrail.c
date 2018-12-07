#include<stdio.h>
#include<stdlib.h>
struct Tnode
{
	struct Tnode *lcptr;
	int data;
	int height;
   struct Tnode *rcptr;
}*rptr=NULL;
struct Tnode* insert(struct Tnode *ptr,int x);
void updateheight(struct Tnode *ptr);
int findheight(struct Tnode *ptr);
void delete();
struct Tnode* RotateRight(struct Tnode *ptr);
struct Tnode* RotateLeft(struct Tnode *ptr);
struct Tnode* RotateRightLeft(struct Tnode *ptr);
struct Tnode* RotateLeftRight(struct Tnode *ptr);
void print(struct Tnode *ptr)
{
	if(ptr!=NULL)
	{
		print(ptr->lcptr);
		printf("%d %d ",ptr->data,ptr->height);
		printf("\n\n");
		print(ptr->rcptr);
	}
}
void main()
{
	
	 int i,x;
	A:	
	printf("Select an option\n1.insert\n2.delete\n3.print\n4.max\n5.min\n\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:printf("enter the number to be inserted\n");scanf("%d",&x);rptr=insert(rptr,x);print(rptr);goto A;break;
		case 2:delete();;goto A;break;
		//case 3:search();goto A;break;
		case 3:printf("\n\ntree has\n\n");
		if(rptr!=NULL)
		{print(rptr);
 		printf("\n\n");}
		else
		printf("nothing\n");
		goto A;break;
		//case 4:max();goto A;break;
		//case 5:min();goto A;break;
	}

	//return 0;
	print(rptr);
	printf("\n\n");
}
struct Tnode* insert(struct Tnode *ptr,int x)
{  
	if(ptr==NULL)
   {
   	ptr=malloc(sizeof(struct Tnode));
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

void delete()
{
	int x;
    	printf("Enter the number to be deleted\n");
	scanf("%d",&x);
	int b;
   	struct Tnode *ptmp=NULL;
	struct Tnode *ptr=rptr;
	struct Tnode *pptr=NULL;	
	while(ptr!=NULL && ptr->data!=x)
	{
		pptr=ptr;		
		if(x>=ptr->data)
			ptr=ptr->rcptr;	
		else 
			ptr=ptr->lcptr;
	}	
	if(ptr==NULL)
	{
		printf("\n Deletion Fails");
	}
	else if(rptr->lcptr==NULL && rptr->rcptr==NULL)
	{
		b=rptr->data;		
		rptr=NULL;	
	}
	else if(ptr==rptr && ( rptr->lcptr==NULL || rptr->rcptr==NULL))
		{
			b=rptr->data;
			if(rptr->lcptr==NULL)
			rptr=rptr->rcptr;
			else
			rptr=rptr->lcptr;
			
		}
	else if(ptr->lcptr==NULL && ptr->rcptr==NULL) //Case 1:Delete Leaf Node
	{
		b=ptr->data;		
		if(x<pptr->data)
			pptr->lcptr=NULL;
		else
			pptr->rcptr=NULL;
	}
	else if(ptr->lcptr==NULL && ptr->rcptr!=NULL || ptr->lcptr!=NULL && ptr->rcptr==NULL)
	{
		b=ptr->data;		
		if(x<pptr->data && ptr->lcptr!=NULL)
			pptr->lcptr=ptr->lcptr;		
		else if(x<pptr->data && ptr->lcptr==NULL)
			pptr->lcptr=ptr->rcptr;
		else if(x>=pptr->data && ptr->lcptr!=NULL)
			pptr->rcptr=ptr->lcptr;
		else
			pptr->rcptr=ptr->rcptr;   
	}
	else
	{		
		struct Tnode *tmp=ptr;
     		ptmp=tmp;		
		tmp=tmp->rcptr;
      
		while(tmp->lcptr!=NULL)
		{
        		ptmp=tmp;
			tmp=tmp->lcptr;
		}
		b=ptr->data;		
		ptr->data=tmp->data;	
			

		//To delete suc node pointed to by tmp, and its parent is ptmp
      
       if(tmp->data < ptmp->data)
         ptmp->lcptr=tmp->rcptr;
       else
         ptmp->rcptr=tmp->rcptr;

	}
	if(ptr!=NULL)
	printf("deleted data is %d\n",b);
	//return b;
}

