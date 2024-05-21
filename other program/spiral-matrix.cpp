#include<iostream>
using namespace std;

int main()
{
    int size;
    cout<<"Enter number of rows"<<endl;
    cin>>size;
    int n=1;
    int a[size][size];
    int r1=0;
    int r2=size-1;
    
    while(r1<=r2)
    {
        if(r1==r2)
        {
            a[r1][r1]=n;
        }
        else
        {
        for(int i=r1 ; i<r2 ; i++)
        a[r1][i]=n++;

        for(int i=r1 ; i<r2 ; i++)
        a[i][r2]=n++;

        for(int i=r2 ; i>r1 ; i--)
        a[r2][i]=n++;

        for(int i=r2 ; i>r1 ; i--)
        a[i][r1]=n++;
        }
        r1++;
        r2--;
        
    }

    cout << "Output Matrix Is :" << endl;
    for(int i=0 ; i<size ; i++)
    {
        for(int j=0 ; j<size ; j++)
        cout << a[i][j] << "\t";
        cout << endl;
    }
}