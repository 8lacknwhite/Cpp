//coded by Nimit Kumar 20070122087
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
		void insert_end();
		void insert_inbet();
		void del_start();
		void del_end();
		void del_inbet();
		void reverse();
		void concatenate();
		
};

void list::create()//Creation of linked list
{
	int i,x,n;
	cout<<"enter number of nodes: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		node*newnode= new node;
		cout<<"enter the data\n";
		cin>>x;
		newnode->data=x;
		newnode->next=NULL;
		if (listptr==NULL)
		{
			listptr=newnode;
			temp=newnode;
		}
		else 
		{
			temp->next=newnode;
			temp=newnode;
		}
	}
}

void list::display()//displaying of list
{
	temp=listptr;
	cout<<temp->data<<"->";
	while (temp->next!=NULL)
	{
		temp=temp->next;
		cout<<temp->data<<"->";
	}
	cout<<"NULL";
}

void list::insert_start()//inserting element at the first position
{
	int a;
	node*newnode = new node;
	cout<<"enter data to insert at beginning";
	cin>>a;
	newnode->next=listptr;
	listptr=newnode;
	newnode->data=a;
	display();
}

void list::insert_end()//inserting element at the end
{
    int x;
    node *newnode = new node;
    cout<<"Enter the value";
    cin>>x;
    while(temp->next!= NULL)
    {
        temp = temp->next;
        cout<<temp->data;
    }
    temp->next = newnode;
    newnode->data = x;
    newnode->next=NULL;
    display();

}

void list::insert_inbet()//inserting element at a given position
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

void list::del_start()//Deletion of first element
{
	temp=listptr;
	listptr=temp->next;
	delete(temp);
	display();
}

void list::del_end()//deletion of last element
{
	node*t;
	temp=listptr;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	t=temp->next;
	temp->next=NULL;
	delete(t);
	display();
}

void list::del_inbet()//deletion at a given position
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

void list::reverse()//reversing the list
{
	node *b,*c,*f;
    f=listptr;
    c=NULL;
    while(f!=NULL)
    {
        b=c;
        c=f;
        f=f->next;
        c->next=b;
    }
    listptr=c;
    display();
}

void list::concatenate()//joining 2 list
{
	list l1,l2;
    cout<<"\nlist 1\n";
    l1.create();
    cout<<"\nlist 2\n";
    l2.create();
    l1.temp=l1.listptr;
    while(l1.temp->next!=NULL)
    {
        l1.temp=l1.temp->next;
    }
    l1.temp->next=l2.listptr;
    cout<<"\nConcatenated List: ";
    l1.temp=l1.listptr;
    while(l1.temp!=NULL)
    {
        cout<<l1.temp->data<<"->";
        l1.temp=l1.temp->next;
    }	
    cout<<"NULL";
}

int main()
{
	int p=1,ch;
	list l;
	while(p==1)//menu
	{
		cout<<"\nenter choice:\n 1)create \n 2)display\n 3)insert at beginning\n 4)insert at end\n 5)insert at intermediate position\n 6)delete from start\n 7)delete from end\n 8)delete from intemediate\n 9)reverse\n 10)concatenate\n\n";
		cin>>ch;
		switch(ch)//switch case function for menu
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
