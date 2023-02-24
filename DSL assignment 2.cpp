//Coded by Nimit Kumar 20070122087
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class node
{
public:
	int data; 
	node* next;
};
class list:public node
{
	node*listptr,*temp;
	public:
		list()
		{
			listptr=NULL;
			temp=NULL;
		}
		void create();
		void display();
		void insert_start();
		void insert_inbet();
		void insert_end();
		void del_start();
		void del_end();
		void del_inbet();
		void reverse();
		void concatenate();
};

void list::create()//list creation
{
	int i,x,n;
	cout<<"enter number of nodes: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter the data\n";
		cin>>x;
		node*newnode= new node;
		newnode->data=x;
		newnode->next=NULL;
		if (listptr==NULL)
		{
			listptr=newnode;
			temp=newnode;
			newnode->next=listptr;
		}
		else 
		{
			temp->next=newnode;
			newnode->next=listptr;
			temp=temp->next;
		}
	}
}

void list::display()//displaying of list
{
	temp=listptr;
	cout<<temp->data<<"->";
	while (temp->next!=listptr)
	{
		temp=temp->next;
		cout<<temp->data<<"->";
	}
	cout<<listptr->data;
}

void list::insert_start()//insterting from start of list
{
	int a;
	node*newnode = new node;
	cout<<"enter data to insert at beginning";
	cin>>a;
	newnode->data=a;
	newnode->next=NULL;
	temp=listptr;
	while (temp->next!=listptr)
	{
		temp=temp->next;
	}
	newnode->next=listptr;
	listptr=newnode;
	temp->next=listptr;
	display();
	
}

void list::insert_end()//insterting from the end of the list
{
	int x;
    node *newnode = new node;
    cout<<"Enter the value";
    cin>>x;
    newnode->data=x;
    temp=listptr;
    while (temp->next!=listptr)
    {
    	temp=temp->next;
	}
	newnode->next=listptr;
	temp->next=newnode;
	display();
}

void list::insert_inbet()//insterting in a given position of list
{
	int p,i=1,n;
	temp=listptr;
	cout<<"enter the position\n";
	cin>>p;
	while(i!=p-1)
	{
		temp=temp->next;
		i++;
	}
	node*newnode=new node;
	cout<<"enter data to enter";
	cin>>n;
	newnode->data=n;
	newnode->next=NULL;
	newnode->next=temp->next;
	temp->next=newnode;
	display();
}

void list::del_start()//deleting element at the start
{
	node*q;
	temp=listptr;
	while (temp->next!=listptr)
	{
		temp=temp->next;
	}
	q=listptr;
	listptr=listptr->next;
	delete(q);
	temp->next=listptr;
	display();
}

void list::del_end()
{
	node*q;
	temp=listptr;
	while(temp->next->next!=listptr)
	{
		temp=temp->next;
	}
	q=temp->next;
	delete(q);
	temp->next=listptr;
	display();
}

void list::del_inbet()//deleteing at a given position
{
	int p,i;
	node*q;
	temp=listptr;
	cout<<"enter the position";
	cin>>p;
	for(i=1;i<p-1;i++)
	{
		temp=temp->next;
	}
	q=temp->next;
	temp->next=q->next;
	delete(q);
	display();
}
	
void list::reverse()//reversing the linked list
{
	node *head=NULL, *prev=listptr->next;
    node *current=listptr;
    while(prev->next!=listptr){
        prev=prev->next;
    }
    while(current->next!=listptr){
        head=current->next;
        current->next=prev;
        prev=current;
        current=head;
    }
    current->next=prev;
    listptr=current;
    display();
}	


void list::concatenate()//join to 2 link list
{
	list l1, l2;
    cout << "List 1" << endl;
    l1.create();
    cout << "List 2" << endl;
    l2.create();
    l1.temp = l1.listptr;
    while (l1.temp->next != l1.listptr)
    {
        l1.temp = l1.temp->next;
    }
    l1.temp->next = l2.listptr;
    l1.temp = l2.listptr;
    while (l1.temp->next != l2.listptr)
    {
        l1.temp = l1.temp->next;
    }
    l1.temp->next = l1.listptr;
    cout << "Concatenated List" << endl;
    l1.temp = l1.listptr;
    while (l1.temp->next != l1.listptr)
    {
        cout << l1.temp->data << "-->";
        l1.temp = l1.temp->next;
    }
    cout << l1.temp->data << "-->" << l1.temp->next->data << endl;
}

int main()
{
	int p=1,ch=1;
	list l;
	while (p==1)//menu creation
	{
		cout<<"\nenter choice:\n 1)create\n 2)display\n 3)insert at start\n 4)insert at end\n 5)insert at intermediate\n 6)delete from start\n 7)delete from last\n  8)delete from intermediate\n 9)reverse \n 10)concatenate\n";
		cin>>ch;
		switch (ch)
		{
			case 1:
				l.create();
				break;
			case 2:
				l.display();
				break;
			case 3:
				l.insert_start();
				break;
			case 4:
				l.insert_end();
				break;
			case 5:
				l.insert_inbet();
				break;
			case 6:
				l.del_start();
				break;
			case 7:
				l.del_end();
				break;
			case 8:
				l.del_inbet();
				break;
			case 9:
				l.reverse();
				break;
			case 10:
				l.concatenate();
				break;
				
		}
		cout<<"\n\nPress 1 to continue\n";
		cin>>p;
	}
}
