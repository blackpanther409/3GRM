#include<iostream>
using namespace std;

class graph
{
	public:
		int n;
		int c[50][50];
		int dist[50];
		int flag;
		int s;
		int count;
		void get();
		void find();
		void print();
};

void graph::get()
{
	count=0;
	cout<<"Enter the number of computers:";
	cin>>n;
	//cout<<"Enter the source node:";
	//cin>>s;
	cout<<"Enter the adjacency matrix:\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
			if(c[i][j]==0)
			{
				c[i][j]=9999;
			}
		}
	}
}

void graph::find()
{
	flag=0;
	for(int i=1;i<=n;i++)
	{
		dist[i]=9999;
	}
	dist[s]=0;
	for(int k=1;k<n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dist[j]>dist[i]+c[i][j] && c[i][j]!=9999)
				{
					dist[j]=dist[i]+c[i][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dist[j]>(dist[i]+c[i][j]) && c[i][j]!=9999)
			{
				flag=1;
				break;
			}
		}
	}
}

void graph::print()
{
	cout<<"Minimum distances from source node\n";
	for(int i=1;i<=n;i++)
	{
		cout<<dist[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	graph g;
	g.get();
	for(int i=1;i<=g.n;i++)
	{
		g.s=i;
		g.find();
		cout<<"For source node:"<<i<<endl;
		if(g.flag==0)
		{	
			g.print();
		}
		else
		{
			cout<<"No shortest path available\n";
		}
	}
	return 0;
}
