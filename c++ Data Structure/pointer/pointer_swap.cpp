#include<iostream>
using namespace std;

int main()
{
    int a=2,b=4;
    swap(a,b);
    cout<<"a = "<<a<<"\t"<<"b = "<<b<<endl;
    return 0;
}

void swap(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
}