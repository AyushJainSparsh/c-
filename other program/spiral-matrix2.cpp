#include<iostream>
using namespace std;

int main()
{
    int r,c;
    cout<<"Enter number of rows"<<endl;
    cin>>r;
    cout<<"Enter number of columns"<<endl;
    cin>>c;
    int n=1;
    int a[r][c];
    int r1=0;
    int r2=r-1;
    int c1=0;
    int c2=c-1;
    
    while(r1<=r2 && c1<=c2)
    {
        
        for(int i=c1 ; i<c2 ; i++)
        a[r1][i]=n++;

        for(int i=r1 ; i<r2 ; i++)
        a[i][c2]=n++;

        for(int i=c2 ; i>c1 ; i--)
        a[r2][i]=n++;

        for(int i=r2 ; i>r1 ; i--)
        a[i][c1]=n++;
        
        r1++;
        r2--;
        c1++;
        c2--;
        
    }

    cout << "Output Matrix Is :" << endl;
    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<c ; j++)
        cout << a[i][j] << "\t";
        cout << endl;
    }
}