#include<iostream>
using namespace std;

class array
{
	public:
		int n,max=0;
		int a[100];
		void get();
		int mode();
};

void array::get()
{
	cout<<"Enter array size:";
	cin>>n;
	cout<<"Enter array elements:";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}

int array::mode()
{
	int m,maxi=0;
	for(int i=0;i<n;i++)
	{
		m=0;
		for(int j=0;j<n;j++)
		{
			if(a[i]==a[j])
			m++;
		}
		if(max<m)
		{
			max=m;
			maxi=i;	
		}
	}
	return a[maxi];
}

int main()
{
	array p;
	p.get();
	int b=p.mode();
	if(p.max==1)
	{
		cout<<"no repetition\n";
	}
	else
	{
		cout<<"The mode is:"<<b<<endl;
	}
	return 0;
}
