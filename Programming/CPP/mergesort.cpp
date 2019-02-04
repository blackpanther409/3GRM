#include<iostream>
using namespace std;

class Array
{
	public:
		int a[100],n;
		void getarray();
		void mergesort(int beg,int end);
		void merge(int beg,int end);	
		void print();	
};

void Array::getarray()
{
	cout<<"Enter the number of elements of the array:";
	cin>>n;
	cout<<"Enter the array elements:";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}

void Array::mergesort(int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		mergesort(beg,mid);
		mergesort(mid+1,end);
		merge(beg,end);
	}
}

void Array::merge(int beg,int end)
{
	int mid=(beg+end)/2;
	int i=beg;
	int j=mid+1;
	int b[n];
	for(int k=0;k<end-beg+1;k++)
	{
		if(i<=mid && j<=end)
		{
			if(a[i]<a[j])
			{
				b[k]=a[i];
				i++;
			}
			else
			{
				b[k]=a[j];
				j++;
			}
		}
		else if(i>mid && j<=end)
		{
			b[k]=a[j];
			j++;
		}
		else if(i<=mid && j>end)
		{
			b[k]=a[i];
			i++;
		}
	}
	for(int k=0;k<end-beg+1;k++)
	{
		a[k+beg]=b[k];
	}
}

void Array::print()
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	Array s;
	s.getarray();
	s.mergesort(0,s.n-1);
	s.print();
	return 0;
}


