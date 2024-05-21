#include<iostream>
using namespace std;

int main()
{
    int n, t1=0 , t2=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<< t1 << " ";
        int t=t1+t2;
        t1=t2;
        t2=t;
    }
    return 0;
}