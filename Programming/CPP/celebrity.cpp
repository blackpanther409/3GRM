#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class celebrity{
	public:
		int n;
		int p[100][100];
		void getrelations();
		void check(int n);
};

void celebrity::getrelations()
{
	cout<<"Enter the number of people:";
	cin>>n;
	cout<<"\nEnter their relations as matrix:\n";
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<n;j++)
		{
			cin>>p[i][j];		
		}
	}		
}

void celebrity::check(int n)
{
	int s[n],c=0,count;
	int a,b;
	for(int i=0;i<n;i++)
	s[i]=1;
	count=n;
	srand(time(0));
	while(count>1)
	{
		a=rand()%n; 
		b=rand()%n;
		//cout<<a<<" "<<b;
		if(p[a][b]==1 || p[b][a]==0)
		{
			if(s[a]!=0)
			count--;
			s[a]=0;
		}	
		else if(p[b][a]==1 || p[a][b]==0)
		{
			if(s[b]!=0)
			count--;
			s[b]=0;
		}
		else if(p[a][b]==0 && p[b][a]==0)
		{
			if(s[a]!=0)
			count--;
			s[a]=0;
			if(s[b]!=0)
			count--;
			s[b]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]==1)
		c=i;
	}
	for(int i=0;i<n;i++)
	{
		if(p[i][c]==0 && c!=i)
		{
			cout<<"No celebrity"<<endl;
			return;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(p[c][i]==1 )
		{
			cout<<"No celebrity"<<endl;
			return;
		}
	}
	cout<<"person "<<c+1<<" is celebrity"<<endl;
	
}

int main()
{
	celebrity star;
	star.getrelations();
	star.check(star.n);
	return 0;
}
