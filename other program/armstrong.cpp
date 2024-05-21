#include<iostream>
using namespace std;
int main()
{
    int n,temp,sum=0;
    cout << "Enter your value :" <<endl;
    cin >> n;
    temp = n;
    while (n>0)
    {
        int d=n%10;
        sum=sum+d*d*d;
        n=n/10;
    }
    if (sum==temp)
    cout << "Number is Armstrong";
    else
    cout << "Number is not Armstrong";
}