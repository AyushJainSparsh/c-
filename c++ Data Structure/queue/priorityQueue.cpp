#include <iostream>
using namespace std;

class queue
{
    public : int size;
    int rear;
    int front;
    int a[];
    int p[];

    queue(int s)
    {
        size=s;
        a[s];
        p[s];
        rear=-1;
        front=-1;
    }

    public : int Enqueue(int data,int prior)
    {
        if(rear==size-1)
        cout<<"\nQueue Overflow\n"<<endl;
        else if(rear==-1)
        {
            
            rear++;
            front++;
            a[rear]=data;
            p[rear]=prior;
        }
        else  
        {
            rear++;
            p[rear]=prior;
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
            int maxp=front;
            for(int i=front;i<=rear;i++)
            {
                if(p[maxp]>p[i])
                maxp=i;
            }
            int ret=a[maxp];
            for(int i=maxp;i>=front;i--)
            {
                a[i]=a[i-1];
                p[i]=p[i-1];
            }
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
            cout<<"\nYour priorities are "<<endl;
            for(int i=front;i<=rear;i++)
            cout<<p[i]<<"\t";
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
                int p;
                cout<<"Enter priority : ";
                cin>>p; 
                q.Enqueue(n,p);
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