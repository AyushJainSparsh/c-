#include<iostream>
using namespace std;

class node
{
    public : int data;
    node* prev;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head, int val)
{
    node* n=new node(val);
    n->next=head;
    if(head!=NULL)
    head->prev=n;
    head=n;
}

void insertAtTail(node* &head,int val)
{
    if(head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    node* n=new node(val);
    node* temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=n;
    n->prev=temp;
}

void display(node* head)
{
    if(head==NULL)
    cout<<"\nList is empty\n"<<endl;
    node* temp=head;
    while(temp->next!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<"\n\n";
}

void deleteHead(node* &head)
{
    node* todelete=head;
    head=head->next;
    head->prev=NULL;

    delete todelete;
}

void deletion(node* &head , int pos)
{
    if(pos==1)
    {
        deleteHead(head);
        return;
    }
    node* temp=head;
    int count = 1;
    while(temp!=NULL && count!=pos)
    {
        temp=temp->next;
        count++;
    }

    temp->prev->next=temp->next;
    if(temp->next!=NULL)
    temp->next->prev=temp->prev;
    delete temp;
}

int main()
{
    node* head=NULL;
    int choice,val;
    do
    {
        cout<<"\nEnter:\n1.insertAtHead"<<endl;
        cout<<"2.insertAtTail"<<endl;
        cout<<"3.display"<<endl;
        cout<<"4.deleteHead"<<endl;
        cout<<"5.deleteAtAnyPosition"<<endl;
        cout<<"0.exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1 :
                cout<<"Enter value : ";
                cin>>val;
                insertAtHead(head,val);
                break;
            case 2 :
                cout<<"Enter value : ";
                cin>>val;
                insertAtTail(head,val);
                break;
            case 3 :
                display(head);
                break;
            case 4 :
                deleteHead(head);
                break;
            case 5 :
                cout<<"Enter Value : ";
                cin>>val;
                deletion(head,val);
                break;
            case 0 :
                break;
            default :
                cout<<"Enter Correct Choice."<<endl;
        }
    }
    while(choice!=0);
    cout<<"\nThank You"<<endl;
}