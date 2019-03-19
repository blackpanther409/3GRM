#include<iostream>
using namespace std;

class greedy
{
	public:
	int denom[100],n;
	int money;
	int freq[100];
	void get();
	void find();
	void print();	
};

void greedy::get()
{
	cout<<"Enter the no of denominations available:";
	cin>>n;
	cout<<"Enter the denominations:";
	for(int i=0;i<n;i++)
	{
		cin>>denom[i];
		freq[i]=0;	
	}
	cout<<"Enter the money:";
	cin>>money;
	
}

void greedy::find()
{
	int m=money,i=n-1;
	while(m>0 && i>=0)
	{
		if(m>=denom[i])
		{
			freq[i]=1;
			m=m%denom[i];
			i--;
		}
		else
		i--;
	}
}

void greedy::print()
{
	cout<<"Frequency of denomintons"<<endl;
	for(int i=0;i<n;i++)
	{
		if(freq[i]>0)
		{
			cout<<"No.of "<<denom[i]<<"'s is:"<<freq[i]<<endl;
		}
	}
}

int main()
{
	greedy g;
	g.get();
	g.find();
	g.print();
	return 0;
}

