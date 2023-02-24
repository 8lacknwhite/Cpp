// coded by Nimit Kumar 20070122087
#include<iostream> 
#include<stdlib.h> 
using namespace std;

struct node
{
public:
	int data; 
	node* next;

};
class list//:public node
{
node*head,*tail; 
public:

	list()
	{
		head=NULL; 
		tail=NULL;

	}
	void create();
	void display();
	void in_start(); 
	void in_end();
	void in_intermediate(); 
	void del_start(); 
	void del_end(); 
	void del_intermediate(); 
	void rev();
	void concat(); 
	void getsize();

};

void list::create()//Creation of linked list
{
	int i,x,n;
	cout<<"enter number of nodes: "; 
	cin>>n;
	for(i=0;i<n;i++)
	{
		struct node*newnode; 
		newnode=new node; 
		cout<<"enter the data\n"; 
		cin>>x;
		newnode->data=x; 
		newnode->next=NULL; 
		if (head==NULL)
		{
			head=newnode;
			tail=newnode;
		}
		else
		{
			tail->next=newnode; 
			tail=newnode;
		}
	}
}

void list::display()//displaying of list
{
	tail=head;
	cout<<tail->data<<"->"; 
	while (tail->next !=NULL)
	{
		tail=tail->next; 
		cout<<tail->data<<"->";
	}
	cout<<"NULL";
}

void list::in_start()//inserting element at the first position
{
	int a;
	node*newnode = new node; 
	cout<<"enter data to insert at beginning"; 
	cin>>a;
	newnode->next=head; 
	head=newnode; 
	newnode->data=a; 
	display();
}

void list::in_end()//inserting element at the end
{
	int x;
	node *newnode = new node
	; cout<<"Enter the value";
	cin>>x;
	while(tail->next!= NULL)
	{
		tail = tail->next;
		cout<<tail->data;
	}
	tail->next = newnode; 
	newnode->data = x; 
	newnode->next=NULL; 
	display();
}

void list::in_intermediate()//inserting element at a given position
{
	int p,i=1,n;
	cout<<"enter the position\n";
	cin>>p; 
	while(i!=p-1)
	{
		tail=tail->next; 
		i++;
	}
	node*newnode=new node; 
	cout<<"enter data to enter"; 
	cin>>n;
	newnode->data=n; 
	newnode->next=NULL; 
	newnode->next=tail->next; 
	tail->next=newnode; 
	display();
}

void list::del_start()//Deletion of first element
{
	tail=head; 
	head=tail->next; 
	delete(tail); 
	display();
}

void list::del_end()//deletion of last element
{
	node*t; 
	tail=head;
	while(tail->next->next!=NULL)
	{
		tail=tail->next;
	}
	t=tail->next;
	tail->next=NULL; 
	delete(t); 
	display();
}

void list::del_intermediate()//deletion at a given position
{
	int p,i; 
	node*q; 
	tail=head;
	cout<<"enter the position"; 
	cin>>p;
	for(i=1;i<p-1;i++)
	{
		tail=tail->next;
	}
	q=tail->next;
	tail->next=q->next; 
	delete(q); 
	display();

}

void list::rev()//reversing the list

{
	node *b,*c,*f; 
	f=head;
	c=NULL;
	while(f!=NULL)
	{
		b=c; c=f;
		f=f->next; 
		c->next=b;
	}
	head=c; 
	display();
}

void list::concat()//joining 2 list
{
	list l1,l2; 
	cout<<"\nlist 1\n"; 
	l1.create(); 
	cout<<"\nlist 2\n"; 
	l2.create(); 
	l1.tail=l1.head;
	while(l1.tail->next!=NULL)
	{
		l1.tail=l1.tail->next;
	}
	l1.tail->next=l2.head; 
	cout<<"\nConcatenated List: "; 
	l1.tail=l1.head; 
	while(l1.tail!=NULL)
	{
		cout<<l1.tail->data<<"->"; 
		l1.tail=l1.tail->next;
	}
	cout<<"NULL";
}

void list::getsize()
{
	int length=0; 
	while(head != NULL)
	{
		head=head->next; 
		length++;
	}
	cout<<"Size of list is "<<length<<endl;
}

int main()
{
	int p=1,ch; list l;
	while(p==1)//menu
	{
		cout<<"\nenter choice:\n 1)create \n 2)display\n 3)insert at beginning\n 4)insert at end\n 5)insert at intermediate position\n 6)delete from start\n 7)delete from end\n 8)delete from intemediate\n 9)reverse\n 10)concatenate\n 11)Size\n\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				l.create();
				break;
			case 2:
				l.display();
				break;
			case 3:
				l.in_start();
				break;
			case 4:
				l.in_end();
				break;
			case 5:
				l.in_intermediate();
				break;
			case 6:
				l.del_start();
				break;
			case 7:
				l.del_end();
				break;
			case 8:
				l.del_intermediate();
				break;
			case 9:
				l.rev();
				break;
			case 10:
				l.concat();
				break;
			case 11:
				l.getsize();
				break;
			default:
				cout<<"Please enter a valid value"<<endl;
				break;
		}	
		cout<<"\n\npress 1 to continue\n";
		cin>>p;
	}
}
