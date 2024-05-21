#include<iostream>
using namespace std;

class complex
{
    public : int imag , real;
    complex( int r=0, int i=0)
    {
        real = r;
        imag =i;
    }

    complex operator + (complex const &c)
    {
        complex r;
        r.real = real + c.real;
        r.imag = imag + c.imag;
        return r;
    }

    int display()
    {
        cout<<real<< " + i"<<imag;
        return 0; 
    }
};


int main()
{
    complex c1(15,6),c2(5,6);
    complex c3=c1 + c2;
    c3.display();
    cout<<"\nThank you";
    return 0;
}