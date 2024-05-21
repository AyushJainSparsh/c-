#include <iostream>
using namespace std;

class fibo_recur
{
    public : int fibo(int n)
    {
        if(n==1 || n==0)
        return n;

        return fibo(n-1)+fibo(n-2);
    }

    int series(int n)
    {
        if(n==0)
        return 0;
        cout<<fibo(n)<<" ";
        return series(--n);
    }
};



int main()
{
    int n;
    cout<<"Enter a number :";
    cin>>n;
    fibo_recur f;
    //cout<<"your number is : "<<f.fibo(--n);
    cout<<"your series is "<<endl;
    cout << f.series(--n);
}