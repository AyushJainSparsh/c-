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

int insertAtHead(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;
    head=n;
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

bool search(node* head,int key)
{
    node* temp=head;
    while(temp!= NULL)
    {
        if(temp->data==key)
        return true;
        temp=temp->next;
    }
    return false;
}

int deletion(node* head,int val)
{
    if(head==NULL)
    return 0;
    if(head->next==NULL)
    cout<<"\nUse delete at head option.\n"<<endl;

    node* temp=head;
    while(temp->next->data!=val)
    temp=temp->next;
    node* del=temp;
    temp->next=temp->next->next;
}


void deleteAtHead(node* &head)
{
    node* del=head;
    head=head->next;
}

node* reverse(node* head)
{
    node* previous=NULL;
    node* current=head;
    while(current!=nullptr)
    {
        node* newptr=current->next;

        current->next=previous;
        previous=current;
        current=newptr;
    }

    return previous;
}

node* reverseRecursive(node* &head)
{
    if(head==NULL || head->next==NULL)
    return head;
    node* newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

node* reversek(node* &head,int k)
{
    node* previous=NULL;
    node* current=head;
    node*nextptr;
    int count=0;
    while(current!=NULL && count<k)
    {
        nextptr=current->next;
        current->next=previous;
        previous=current;
        current=nextptr;
        count++;
    }

    if(nextptr!=NULL)
    head->next=reversek(nextptr,k);
    return previous;
}

int length(node* head)
{
    int c=0;
    node* temp=head;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}

node* append(node* &head, int k)
{
    int l=length(head);
    node* newTail;
    node* newHead;
    node* tail=head;
    int c=0;
    while(tail->next!=NULL)
    {
        if(c==l-k)
        newTail=tail;
        if(c==l-k+1)
        newHead=tail;
        tail=tail->next;
        c++;
    }
    newTail->next=NULL;
    tail->next=head;
    return newHead;
}

int main()
{
    node* head=NULL;
    int choice , val ;
    do
    {
        cout<<"Enter\n 1.Insert At Tail"<<endl;
        cout<<" 2.Insert At Head"<<endl;
        cout<<" 3.Display"<<endl;
        cout<<" 4.Searching"<<endl;
        cout<<" 5.Delete"<<endl;
        cout<<" 6.Deletion At Head"<<endl;
        cout<<" 7.Reverse"<<endl;
        cout<<" 8.Reverse by recursion"<<endl;
        cout<<" 9.Reverse k elements"<<endl;
        cout<<"10.Append"<<endl;
        cout<<"0.Exit"<<endl;

        cin>>choice;
        switch(choice)
        {
            case 0:
                break;
            case 1:
                cout<<"Enter Element : ";
                cin>>val;
                insertAtTail(head,val);
                break;
            case 2:
                cout<<"Enter Element : ";
                cin>>val;
                insertAtHead(head,val);
                break;
            case 3:
                display(head);
                break;
            case 4: 
                cout<<"Enter Value : ";
                cin>>val;
                if(search(head,val))
                cout<<"\nElement Found\n"<<endl;
                else
                cout<<"\nElement not Found\n"<<endl;
                break;
            case 5:
                cout<<"Enter Value : ";
                cin>>val;
                deletion(head,val);
                break;
            case 6:
                deleteAtHead(head);
                break;
            case 7:
                head=reverse(head);
                break;
            case 8:
                head=reverseRecursive(head);
                break;
            case 9:
                cout<<"Enter a value : ";
                cin>>val;
                head=reversek(head,val);
                break;
            case 10:
                cout<<"Enter a value : ";
                cin>>val;
                head=append(head,val);
                break;
            default:
                cout<<"Enter correct choice."<<endl;
        }
    }
    while(choice!=0);
}