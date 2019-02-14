#include<iostream>
#include<cmath>
using namespace std;

class array
{
	public:
		int size;
		int a[100],b[100];
		int partition(int beg,int end);
		int select(int* a,int beg,int end,int i,int n);
};

int array::select(int* a,int beg,int end,int i,int n)
{
	if(n<=5)
	{
		 //sort the elements and get ith min
	}
	
	//write code for dividing groups of size and find their medians and store in b[0,1.....ceiling(n/5)
	
	int x,k;
	x=select(b,1,ceiling(n/5),(ceiling(n/5))/2,ceiling(n/5));
	k=partition(a,beg,end,x);
	if(i==k)
	{
		return x;
	}
	else if(i<k)
	{
		y=select(a,beg,k-1,i,k-beg);
		return y;
	}
	else
	{
		y=select(a,k+1,end,i-k,end-k);
		return y;
	}
}

int array::partition(int beg,int end)
{
	int i=beg+1;
	int j=end;
	int pivot=a[beg];
	while(i<j)
	{
		while(a[i]<=pivot && i<=end)
		{
			i++;
		}
		while(a[j]>pivot && j>beg)
		{
			j--;
		}
		if(i<j)
		{
			swap(i,j);
		}
	}
	if(a[beg]>a[j])
	{	
		swap(j,beg);
	}
	return j;
}

int main()
{
	
	
	
	return 0;
}
