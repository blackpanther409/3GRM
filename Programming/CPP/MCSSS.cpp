#include<iostream>
using namespace std;
class Array
{
	public:
	int MCSSS1(int *a,int n);
	int MCSSS2(int *a,int n);
	int MCSSS3(int *a,int beg,int end);
	int MCSSS4(int *a,int n);
	int max(int a,int b,int c);

};

int Array::MCSSS1(int *a,int n)				//brute force method
{
	int msum=0,sum=0;
	for(int i=0;i<=n-1;i++)
		for(int j=i;j<=n-1;j++)
		{
			sum=0;
			for(int k=i;k<=j;k++)
			{
				sum=sum+a[k];
				if(msum<sum)
					msum=sum;
			}
		}		
	return msum;
}

int Array::MCSSS2(int *a,int n)				//iterating method
{
	int msum=0,sum=0;
	for(int i=0;i<=n-1;i++)
	{
		sum=0;
		for(int j=i;j<=n-1;j++)
		{
			sum=sum+a[j];
			if(msum<sum)
				msum=sum;
		}	
	}
	return msum;

}

int Array::MCSSS3(int *a,int beg,int end)	//divide and conqure method
{
	if(beg==end)	
	{
		if(a[beg]<0)
		return 0;	
		else
		return a[beg];
	}
	int mid=0;
	mid=(beg+end)/2;
	int LS=MCSSS3(a,beg,mid);
	int RS=MCSSS3(a,mid+1,end);
	int rosum,losum,rsum,lsum,msum;
	rsum=lsum=losum=rosum=0;
	for (int i=mid;i<=end;++i)
	{
		rsum=rsum+a[i];
		if(rsum>rosum)
		rosum=rsum;
	}
	for (int i=mid-1;i>=beg;--i)
	{
		lsum=lsum+a[i];
		if(lsum>losum)
		losum=lsum;
	}
	msum=rosum+losum;
	return max(RS,LS,msum);
}

int Array::max(int a,int b,int c)				//max function for D & C
{
	
	if(a>=b && a>=c)
	return a;
	else if(b>=a && b>=c)
	return b;
	else
	return c;
}

int Array::MCSSS4(int *a,int n)					//pruning method
{
	int msum=0,csum=0;
	for(int i=0;i<=n-1;i++)
	{
		csum=csum+a[i];
		if(csum<0)
		csum=0;
		if(csum>msum)
		msum=csum;
	}
	return msum;
}

int main()
{
	Array A;
	int n;
	cout<<"Enter array size"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter array elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"BY Brute force method with time complexity        O(n^3) :"<<A.MCSSS1(a,n)<<endl;
	cout<<"BY Iteration method with time complexity          O(n^2) :"<<A.MCSSS2(a,n)<<endl;
	cout<<"BY Divide and Conquer method with time complexity O(nlogn) :"<<A.MCSSS3(a,0,n-1)<<endl;
	cout<<"BY Pruning method with time complexity            O(n) :"<<A.MCSSS4(a,n)<<endl;
}


