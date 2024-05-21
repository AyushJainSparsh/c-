#include<iostream>
using namespace std;

class pallindrome
{
    public : int check()
    {
    int n,temp,rev=0;
    cout << "Enter your value :" <<endl;
    cin >> n;
    temp = n;
    while (n>0)
    {
        int d=n%10;
        rev=rev*10+d;
        n=n/10;
    }
    if (rev==temp)
    cout << "Number is pallindrome";
    else
    cout << "Number is not pallindrome";
    }
};

class inherit : public pallindrome
{
    public : void inside()
    {
        check();
    }
};

int main()
{
    inherit p;
    p.inside();
}