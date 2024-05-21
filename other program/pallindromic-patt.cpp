/*
_-_-_1
    212
   32123
  4321234
*/

#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Please Enter a value : ";
    cin>>n;
    for (int i=n; i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        cout<<" ";
        for(int j=(n-i+1);j>=1;j--)
        cout<<j;
        for(int j=2;j<=(n-i+1);j++)
        cout<<j;
        cout<<endl;
    }
    return 0;
}