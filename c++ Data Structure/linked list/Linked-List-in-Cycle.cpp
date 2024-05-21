#include <iostream>
using namespace std;

class node
{
    public :
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

int insertAtTail(node* &head, int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        head=n;
        return 0;
    }
    node* temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=n;
}

node* cycle(node* head,int pos)
{
    node* temp=head;
    node* start;
    int count=0;
    while(temp->next!=NULL)
    {
        if(++count==pos)
        start=temp;
        temp=temp->next;
    }
    temp->next=start;
}

int display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<"\n"<<endl;
}

bool detectCycle(node* head)
{
    node* turtle=head;
    node* rabbit=head;
    while(rabbit!=NULL && rabbit->next!=NULL)
    {
        rabbit=rabbit->next->next;
        turtle=turtle->next;

        if(rabbit==turtle)
        return true;
    }
    return false;
}

node* removeCycle(node* &head)
{
    node* turtle=head;
    node* rabbit=head;
    do
    {
        turtle=turtle->next;
        rabbit=rabbit->next->next;
    }
    while(turtle!=rabbit);
    rabbit=head;
    while(turtle->next!=rabbit)
    {
        turtle=turtle->next;
        rabbit=rabbit->next;
    }
    rabbit->next=NULL;
}

int main()
{
    node* head=NULL;
    int choice , val ;
    do
    {
        cout<<"Enter\n1.Insert At Tail"<<endl;
        cout<<"2.Cycle"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Detect Cycle"<<endl;
        cout<<"5.Remove Cycle"<<endl;
        cout<<"0.exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter a value : ";
                cin>>val;
                insertAtTail(head,val);
                break;
            case 2:
                cout<<"Enter your position : ";
                cin>>val;
                cycle(head,val);
                break;
            case 3:
                display(head);
                break;
            case 4:
                if(detectCycle(head))
                cout<<"\nCycle Detected\n"<<endl;
                else
                cout<<"\nCycle not Detected\n"<<endl;
                break;
            case 5:
                if(detectCycle(head))
                removeCycle(head);
                break;
            case 0:
                break;
            default:
                cout<<"Enter correct choice."<<endl;
        }
    }
    while(choice!=0);
    return 0;
}