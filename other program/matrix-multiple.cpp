#include<iostream>
using namespace std;

int main()
{
    int r ;
    cout << "Enter size of array" << endl;
    cin >> r ;
    int a[r][r];
    int b[r][r];
    int c[r][r];
    
    cout << "Enter elements of first Matrix" << endl;
    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<r ;j++)
        cin >> a[i][j];
    }
    
    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<r ; j++)
        c[i][j]=0;
    }

    cout << "Enter elements of second Matrix" << endl;
    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<r ;j++)
        cin >> b[i][j];
    }



    for (int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<r ; j++)
        {
            for(int k=0; k<r ;k++)
            c[i][j]+=a[j][k]*b[k][j];
        }
    }

    cout << "Matrix a is" << endl;
    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<r ; j++)
        cout << a[i][j] << "\t";
        cout << endl;
    }

    
    cout << "Matrix b is" << endl;
    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<r ; j++)
        cout << b[i][j] << "\t";
        cout << endl;
    }

    
    cout << "Matrix c is" << endl;
    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<r ; j++)
        cout << c[i][j] << "\t";
        cout << endl;
    }
}