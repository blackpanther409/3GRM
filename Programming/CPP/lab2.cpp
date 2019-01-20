#include<iostream>
#include<stdlib.h>
using namespace std;
class Search
{
  public:
  int a[100],x;
  int Sorting();
  int LinearSearch();
  int BinarySearch();

};
int main()
{
  Search s;
  int count1,count2;
  float p,q,sum1=0,sum2=0;
  cout<<"linear search      "<<"binary search\n";
  for(int j=0;j<1000;j=j+1)
  { 
    for(int i=0;i<100;i=i+1)
    {
       s.a[i]=rand()%101;
       //cout<<s.a[i]<<" ";
    }
    //cout<<" the number to be searched";
    s.x=rand()%101;
    //cout<<"the  number"<<s.x;
    
    count1=s.LinearSearch();
    s.Sorting();
    count2=s.BinarySearch();
    
    cout<<count1<<"                   "<<count2<<"\n";
    sum1=sum1+count1;
    sum2=sum2+count2;
    
   }
   p=sum1/1000;
    q=sum2/1000;
    cout<<"average for linear search  "<<p<<"\n";
    cout<<"average for binary search  "<<q<<"\n";
    
  return(0);
}
int Search::Sorting()
{
 for(int i=1;i<99;i=i+1)
    {
      for(int j=i;j>=0;j=j-1)
      {
        
          if(a[j]<a[j-1])
           {
             int swap=a[j];
             a[j]=a[j-1];
             a[j-1]=swap;
           }
          else
          break;
      }
    }
 return(0);
}
int Search::LinearSearch()
{
   int count1=0;
   for(int i=0;i<100;i=i+1)
   {
       count1=count1+1;
       if(a[i]==x)
       {
         break;
       }
   }
  return(count1);
}

int Search::BinarySearch()
{
   int count2=0,beg=0,end=99,mid;
   while(beg<=end)
   {
      mid=(beg+end)/2;
      count2=count2+1;
      if(x==a[mid])
      {
      
        break;
      }
      else if(x<a[mid])
      {
        end=mid-1;
      }
      else
      {
        beg=mid+1;
      }
      
   }
   
   return(count2);
}
