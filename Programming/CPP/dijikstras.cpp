#include<iostream>
using namespace std;

class graph
{
	public:
		int n;
		int c[50][50];
		int dist[50];
		int mark[50];
		int s;
		void get();
		void find();
		void print();
};

void graph::get()
{
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
		}
	}
}

void graph::find()
{
	int min,p;
	for(int i=1;i<=n;i++)
	{
		mark[i]=0;
		dist[i]=c[s][i];
		if(dist[i]==0 && i!=s)
		{
			dist[i]=9999;
		}
	}
	mark[s]=1;
	for(int i=1;i<=n;i++)
	{
		min=9999;
		for(int j=1;j<=n;j++)
		{
			if(min>dist[j] && mark[j]==0 && dist[j]!=0)
			{
				min=dist[j];
				p=j;
			}
		}
		mark[p]=1;
		for(int j=1;j<=n;j++)
		{
			if(mark[j]!=1 && dist[j]>(dist[p]+c[j][p]) && c[j][p]!=0)
			{
				dist[j]=dist[p]+c[j][p];
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
		g.print();
	}
	return 0;
}
