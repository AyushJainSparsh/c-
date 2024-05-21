#include <iostream>
using namespace std;

class recursion_fact
{
    public : int fact(int n)
    {
        if ( n <= 1)
        return 1;
        else 
        return n * fact( --n );
    }
};

int main()
{
    int c;

    cout << " Enter a number please : " << endl;
    cin >> c;
    recursion_fact rf;
    int o=rf.fact(++c);
    cout << "factorial = " << o << endl;
    return 0;
}
