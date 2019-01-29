#include<iostream>
using namespace std;

class dosa{
	public:
		int a[100];
		int getdosas();
		int numflips(int *a);
		void flipdosas(int end,int *a);
		int findmax(int p,int *a);
};

int dosa::getdosas()
{
	int n;
	cout<<"Enter the number of dosas:";
	cin>>n;
	cout<<"\nEnter the radii of dosas"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	return n;
}

int dosa::numflips(int *a)
{
	int n=getdosas();
	int flips=0;
	for(int i=n-1;i>=0;i--)
	{
		if(a[findmax(i,a)]!=a[i])
		{
			flipdosas(findmax(i,a),a);
			flips++;
			flipdosas(i,a);
			flips++;
		}	
	}
	return flips;
}

void dosa::flipdosas(int end,int *a)
{
	int temp;
	for(int i=0;i<=end/2;i++)
	{
		temp=a[i];
		a[i]=a[end-i];
		a[end-i]=temp;
	}
	
	//for(int i=0;i<6;i++)
	//cout<<a[i]<<" ";
	//cout<<"\n";
}

int dosa::findmax(int p,int *a)
{
	int max=a[0],j=0;
	for(int i=0;i<=p;i++)
	{
		if(max<a[i])
		{
			max=a[i];
			j=i;
		}
	}
	return j;
}

int main()
{
	dosa d1;
	cout<<"Min number of flips:"<<d1.numflips(d1.a)<<endl;
	for(int i=0;i<6;i++)
	cout<<d1.a[i]<<endl;
	return 0;
}
