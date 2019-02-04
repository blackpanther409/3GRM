#include<iostream>
using namespace std;

class array
{
	public:
		int a[100],n;	
		void getarray();
		void quicksort(int beg,int end);
		int partition(int beg,int end);
		void printarray();
		void swap(int a, int b);
};

void array::getarray()
{
	
	cout<<"Enter the number of elements of the array\n";
	cin>>n;
	cout<<"Enter the elements of the array\n";
	for(int i=0;i<n;i++)
	cin>>a[i];
}

void array::quicksort(int beg,int end)
{
	int j;
	if(beg<end)
	{
		j=partition(beg,end);
		quicksort(beg,j-1);
		quicksort(j+1,end);
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

void array::printarray()
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<"\n";
}

void array::swap(int x,int y)
{
	int temp;
	temp=a[x];
	a[x]=a[y];
	a[y]=temp;
}

int main()
{
	array A;
	A.getarray();
	A.quicksort(0,(A.n)-1);
	A.printarray();
	return 0;
}


