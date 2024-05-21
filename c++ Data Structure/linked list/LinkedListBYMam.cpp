#include <iostream>  
using namespace std; 
//create a node 
class node{
	public:
		int key;
		int data;
		node* next;
		node()
		{
			key=0;
			data=0;
			next=NULL;
			 
		}
		node(int k,int d)
		{
			key=k;
			data=d;
			
		}
};
//create a singly linked list
class singlelinklist{
		public:
			node* head;
		singlelinklist()
		{
			head=NULL;
		}
		singlelinklist(node* n)
		{
			head=n;
		}
	//node exist using key value
		node* nodeExist(int k)		
	{
			node* temp=NULL;
			node* ptr=head;
			
		
		while(ptr!=NULL)
		{
			if(ptr->key==k)
			{
				temp=ptr;	
			}
			ptr=ptr->next;
		}
		return temp;
	}
			

	//append node
	void app(node* n)
	{	
		if(nodeExist(n->key)!=NULL)
		{
			cout<<"node already exist"<<n->key<<endl;
		}
		else
		{
			if(head==NULL)
			{
				head=n;
				cout<<"node appended "<<endl;
			
			}
			else
			{
				node* ptr=head;
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
				ptr->next=n;
			cout<<"node appended "<<endl;
			}
		}
	}
	void print()
	{
		if(head==NULL)
		{
			cout<<" no node appended "<<endl;
		}
		else
		{
			cout<<" list vales ";
			node*temp=head;
		
			while(temp!=NULL)
		    {
		       cout<<"("<<temp->key<<","<<temp->data<<")->";
		       temp= temp->next;
			}
		}
	}
};

   
int main ()
{  
	singlelinklist s;
	int option;
	int key1,k1,data1;
	do
	{
		cout<<"\nwhat operation do u want to perform.enter 0 to  exit "<<endl;
		cout<<"1...app() "<<endl;
		cout<<"2...print() "<<endl;
		cin>>option;
		node* n1=new node();
		switch(option)
		{	
			case 0:
			break;
	  		case 1:
			cout<<" append operation "<<endl;
			cin>>key1;
			cin>>data1;
			n1->key=key1;
			n1->data=data1;
			s.app(n1);
			break;
	    	default:
			cout<<"wrong choise "<<endl;
			case 2:
	  		s.print();
		}
	}
	while(option!=0);
	return 0;
}