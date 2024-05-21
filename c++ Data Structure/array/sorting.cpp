#include<iostream>
using namespace std;

int main()
{
    cout<<"\nEnter size of array : ";
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter Elements :\n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    //original array
    cout<<"\nOriginal Array : \n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<"\t";
    //sorting
    for(int i=0;i<n-1;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    //output
    cout<<"\nSorted Array : \n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<"\t";
}