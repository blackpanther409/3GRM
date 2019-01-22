#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;
class DNA
{
	public:
	int S[20],F[20],firsts,lasts,firstf,lastf,first,last,f,l;
	void read();
	int bruteforce(int *a);
	int incDesgn(int *a);
	int divideNconquer(int *a,int beg,int end);
	int pruning(int *a);
	int max(int a,int b,int c);
	void test(int diff);
	void print(int *a,int first,int last);
};

void DNA::read()
{
	//char s;
	int s;
	int array[4];
	array[0]=-2;
	array[1]=-1;
	array[2]=1;
	array[3]=2;
	srand(time(0));
	//cout<<"Enter the pattern of son's DNA:"<<endl;
	for(int i=0;i<20;i++)
	{	
		s=array[rand()%4];
		S[i]=s;
		/*if(s=='A')
		S[i]=2;
		else if(s=='C')
		S[i]=1;
		else if(s=='G')
		S[i]=-1;
		else if(s=='T')
		S[i]=-2;*/
	}
	//cout<<"Enter the pattern of father's DNA:"<<endl;	
	for(int i=0;i<20;i++)
	{
		//cin>>s;
		s=array[rand()%4];
		/*S[i]=s;
		if(s=='A')
		F[i]=2;
		else if(s=='C')
		F[i]=1;
		else if(s=='G')
		F[i]=-1;
		else if(s=='T')
		F[i]=-2;*/
	}
	
	
	firsts=0;
	lasts=19;
	firstf=0;
	lastf=19;
}

int DNA::bruteforce(int *a)
{
	int sum=0;	
	int msum=0;
	for(int i=0;i<20;i++)
	{
		for(int j=i;j<20;j++)
		{
			sum=0;	
			for(int k=i;k<=j;k++)
			{
				sum=sum+a[k];
				if(sum>msum)
				{	
					first=i;
					msum=sum;
					last=k;
				}
			}
		}
	}
	return msum;
}

int DNA::incDesgn(int *a)
{
	int sum=0;
	int msum=0;
	for(int i=0;i<20;i++)
	{
		sum=0;
		for(int j=i;j<20;j++)
		{
			sum=sum+a[j];
			if(sum>msum)
			msum=sum;
		}
	}
	return msum;
}

int DNA::divideNconquer(int *a,int beg,int end)
{
	if(beg==end)
	{
		if(a[beg]<0)
		return 0;
		else
		return a[beg];
	}
	int LS,RS;
	int mid=(beg+end)/2;
	LS=divideNconquer(a,beg,mid);
	f=beg;
	RS=divideNconquer(a,mid+1,end);
	l=end;
	int rosum,losum,rsum,lsum,msum=0;
	rosum=losum=rsum=lsum=0;
	for(int i=mid-1;i>=beg;i--)
	{	
		lsum=lsum+a[i];
		if(lsum>losum)
		losum=lsum;
	}
	for(int i=mid;i<=end;i++)
	{
		rsum=rsum+a[i];
		if(rsum>rosum)
		rosum=rsum;
	}
	msum=rosum+losum;
	return max(msum,LS,RS);
}

int DNA::max(int a,int b,int c)
{
	if(a>b && a>c)
	return a;
	else if(b>a && b>c)
	return b;
	else if(c>a && c>b)
	return c;
}

int DNA::pruning(int *a)
{
	int csum=0,msum=0;
	for(int i=0;i<20;i++)
	{
		csum=csum+a[i];
		if(csum<0)
		csum=0;
		if(csum>msum)
		msum=csum;
	}
	return msum;
}

void DNA::test(int diff)
{
	if(diff<10 && diff>-10)					
	{
		cout<<"positive"<<endl;	
	}
	else
	{
		cout<<"negative"<<endl;
	}
}

void DNA::print(int *a,int first,int last)
{
	for(int i=first;i<=last;i++)
	{
		char s;
		if(a[i]==2)
		s='A';
		else if(a[i]==1)
		s='C';
		else if(a[i]==-1)
		s='G';
		else if(a[i]==-2)
		s='T';
		cout<<s;
	}
	cout<<endl;
}

int main()
{
	DNA d;
	d.read();
	int diff,A,B;
	diff=d.divideNconquer(d.S,0,19)-d.divideNconquer(d.F,0,19);		//D&C			
	d.test(diff);
	diff=d.incDesgn(d.S)-d.incDesgn(d.F);						//incdesign
	d.test(diff);
	diff=d.pruning(d.S)-d.pruning(d.F);							//pruning
	d.test(diff);
	A=d.bruteforce(d.S);
	d.firsts=d.first;
	d.lasts=d.last;
	B=d.bruteforce(d.F);										//bruteforce
	d.firstf=d.first;
	d.lastf=d.last;
	diff=A-B;
	d.test(diff);	
	d.print(d.S,d.firsts,d.lasts);
	d.print(d.F,d.firstf,d.lastf);	
	d.print(d.S,d.f,d.l);														
	return 0;
}





