#include<iostream>
using namespace std;

class overloading
{
    public : void fun()
    {
        cout<<"trying overloading\n";
    }

    void fun(int a)
    {
        cout<<"trying overloading with integers\n";
    }

    void fun(double n)
    {
       cout<<"trying overloading with double\n";
    }
};

int main()
{
    overloading o;
    o.fun();
    o.fun(2);
    o.fun(9.0);
}