#include<iostream>
#include<math.h>
using namespace std;

class greedyprice
{
	public:
	float price[100],n;
	float maxw;
	float weight[100];
	float ratio[100];
	int freq[100];
	void get();
	void find();
	void print();	
};

void greedyprice::get()
{
	cout<<"Enter the no of objects available:";
	cin>>n;
	cout<<"Enter the prices of objects:";
	for(int i=0;i<n;i++)
	{
		cin>>price[i];
		freq[i]=(i+1)*(-1);	
	}
	cout<<"Enter the weights of objects:";
	for(int i=0;i<n;i++)
	{
		cin>>weight[i];
		ratio[i]=price[i]/weight[i];
	}
	cout<<"Enter the bag capacity:";
	cin>>maxw;
	//sorting with respect to prices
	int temp;
	for(int i=1;i<n;i++)
	{
		for(int j=i;j>0;j--)
		{
			if(ratio[j]<ratio[j-1])
			{
				temp=ratio[j];
				ratio[j]=ratio[j-1];
				ratio[j-1]=temp;				
				temp=price[j];
				price[j]=price[j-1];
				price[j-1]=temp;
				temp=weight[j];
				weight[j]=weight[j-1];
				weight[j-1]=temp;
				temp=freq[j];
				freq[j]=freq[j-1];
				freq[j-1]=temp;
			}
			else
			break;
		}
	}
}

void greedyprice::find()
{
	float m=maxw,sum=0;
	int i=n-1;
	while(m>0 && i>=0)
	{
		if(m>=weight[i] && m>0)
		{
			freq[i]=freq[i]*(-1);
			m=m-weight[i];
			sum=sum+price[i];
			//cout<<price[i]<<" : "<<weight[i]<<endl;
			i--;
		}
		else
		i--;
	}
	cout<<"sum:"<<sum<<endl;
}

void greedyprice::print()
{
	cout<<"Objects that can be taken"<<endl;
	for(int i=0;i<n;i++)
	{
		if(freq[i]>0)
		{
			cout<<"object "<<freq[i]<<endl;
		}
	}
}

int main()
{
	greedyprice g;
	g.get();
	g.find();
	g.print();
	return 0;
}
