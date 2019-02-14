#include<iostream>
#include<string.h>
using namespace std;

class word
{
	public:
		string s;
		string meaning;
};

class dictionary
{
	public:
		int n;
		word w[100];
		void addset();
		void addword();
		void print();
		void mergesort(int beg,int end);
		void merge(int beg,int end);	
};

void dictionary::addset()
{
	cout<<"Enter the number of words:";
	cin>>n;
	cout<<"Enter the words and meanings\n";
	for(int i=0;i<n;i++)
	{
		cin>>w[i].s;
		cin>>w[i].meaning;
	}
	
}

void dictionary::mergesort(int beg,int end)
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

void dictionary::merge(int beg,int end)
{
	int mid=(beg+end)/2;
	int i=beg;
	int j=mid+1;
	string b[n];
	string c[n];
	for(int k=0;k<end-beg+1;k++)
	{
		if(i<=mid && j<=end)
		{
			if(w[i].s<w[j].s)
			{
				b[k]=w[i].s;
				c[k]=w[i].meaning;
				i++;
			}
			else
			{
				b[k]=w[j].s;
				c[k]=w[j].meaning;
				j++;
			}
		}
		else if(i>mid && j<=end)
		{
			b[k]=w[j].s;
			c[k]=w[j].meaning;
			j++;
		}
		else if(i<=mid && j>end)
		{
			b[k]=w[i].s;
			c[k]=w[i].meaning;
			i++;
		}
	}
	for(int k=0;k<end-beg+1;k++)
	{
		w[k+beg].s=b[k];
		w[k+beg].meaning=c[k];
	}
}

void dictionary::addword()
{
	string p,q;
	cout<<"Enter the word:";
	cin>>p;
	cout<<"Enter it's meaning:";
	cin>>q;
	int i=0;
	while(w[i].s<p)
	{
		i++;
	}
	if(i==n)
	{
		n=n+1;
		w[n-1].s=p;
		w[n-1].meaning=q;
	}
	else
	{
		n=n+1;
		for(int k=n-1;k>=i;k--)
		{
			w[k].s=w[k-1].s;
			w[k].meaning=w[k-1].meaning;
		}
		w[i].s=p;
		w[i].meaning=q;
	}
}

void dictionary::print()
{
	for(int i=0;i<n;i++)
	{
		cout<<w[i].s<<":";
		cout<<w[i].meaning<<endl;
	}
}

int main()
{
	dictionary d;
	d.addset();
	d.mergesort(0,d.n-1);
	cout<<"**********************************\n";
	d.print();
	cout<<"**********************************\n";
	d.addword();
	d.print();
	return 0;
}
