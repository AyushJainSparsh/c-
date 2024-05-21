#include <iostream>
using namespace std;
class stack
{
    public : int size;
    int top;
    int a[];

    stack( int s)
    {
        size = s;
        a[s];
        top=-1;
    }

    public : int push(int n)
    {
        if (top!=size)
        a[++top]=n;
        else
        cout<<"\nStack Overflow\n"<<endl;
        return 0;
    }

    int pop()
    {
        if(top==-1)
        cout<<"\nStack Underflow\n"<<endl;
        else
        --top;
        return a[top+1];
    }

    int display()
    {
        if(top==-1)
        cout<<"\nStack Underflow\n"<<endl;
        else
        {
            cout<<"Your Elements : "<<endl;
            for(int i=top;i>=0;i--)
            cout<<a[i]<<"\t";
        }
        cout<<endl;
        return 0;
    }
};

int main()
{
    int s;
    cout<<"Enter size please : ";
    cin >> s;
    stack st(s);
    int choice;
    do
    {
        cout<<"\nEnter \n 1.push"<<endl;
        cout<<" 2.pop"<<endl;
        cout<<" 3.display"<<endl;
        cout<<" 0.exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 0:
                break;
            case 1:
                cout<<"Enter Element :  ";
                int n;
                cin >> n;
                st.push(n);
                break;
            case 2:
                cout<<st.pop()<<endl;
                break;
            case 3:
                st.display();
                break;
            default:
                cout<<"Enter correct choice."<<endl;
        }
    }
    while(choice!=0);
    cout<<"\nThank you for using my stack.";
}