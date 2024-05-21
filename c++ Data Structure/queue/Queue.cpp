#include <iostream>
using namespace std;

class queue
{
    public : int size;
    int rear;
    int front;
    int a[];

    queue(int s)
    {
        size=s;
        a[s];
        rear=-1;
        front=-1;
    }

    public : int Enqueue(int data)
    {
        if(rear==size-1)
        cout<<"\nQueue Overflow\n"<<endl;
        else if(rear==-1)
        {
            
            rear++;
            front++;
            a[rear]=data;
        }
        else  
        {
            rear++;

            a[rear]=data;
        }
        return 0;
    }

    int Dequeue()
    {
        if(front==-1)
        cout<<"\nQueue Underflow\n"<<endl;
        else
        {
            int ret=a[front];
            front++;
            return ret;
        }
    }

    int display()
    {
        if(front==-1)
        cout<<"\nQueue Underflow\n"<<endl;
        else
        {
            cout<<"\nYour Elements are "<<endl;
            for(int i=front;i<=rear;i++)
            cout<<a[i]<<"\t";
            cout<<"\n"<<endl;
        }
    }
};

int main()
{
    int n;
    cout<<"Enter Size : ";
    cin>>n;
    queue q(n);
    int choice;
    do
    {
        cout<<"Enter :\n1.Enqueue\n2.Dequeue\n3.display"<<endl;
        cout<<"0.Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter Element : ";
                cin>>n;
                q.Enqueue(n);
                break;
            case 2:
                cout<<q.Dequeue()<<endl;
                break;
            case 3:
                q.display();
                break;
            case 0:
                break;
            default:
                cout<<"Enter correct choice."<<endl;
        }
    }
    while(choice!=0);
    cout<<"\nThank You For Using My Queue\n";
}