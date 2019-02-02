#include<iostream>
using namespace std;

class array
{
	public:
		int a[100],n;	
		void getarray();
		void quicksort(int beg,int end);
		int partition(int beg,int end);
		void printarray();
};

void array::getarray()
{
	
	cout<<"Enter the number of elements of the array\n";
	cin>>n;
	cout<<"Enter the elements of the array\n";
	for(int i=0;i<n;i++)
	cin>>a[i];
}

void array::quicksort(int beg,int end)
{
	int j;
	if(beg<end)
	{
		j=partition(beg,end);
		quicksort(beg,j-1);
		quicksort(j+1,end);
	}

}

int array::partition(int beg,int end)
{
	int pivot=a[end];  
 	int temp;
    int i=beg-1;   

    for (int j=beg;j<=end-1;j++)
    {
        if (a[j]<=pivot)
        {
            i++;     
            temp=a[i]; 
    		a[i]=a[j];
    		a[j]=temp; 
        }
    }
    temp=a[i+1]; 
    a[i+1]=a[end];
    a[end]=temp;
    return (i+1);	 
}

void array::printarray()
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<"\n";
}

int main()
{
	array A;
	A.getarray();
	A.quicksort(0,(A.n)-1);
	A.printarray();
	return 0;
}


