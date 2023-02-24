//Coded By Nimit Kumar 20070122087
#include<stdio.h> 
#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

struct node{ 
	int data;
	struct node *left; 
	struct node *right;
};

struct node* createNode(int val)
{
	struct node* Node = new node; 
	Node->data = val;
	Node->left = NULL; 
	Node->right = NULL; 
	return (Node);
}

 
void Inorder(node *temp){
	if (temp == NULL){
		return;
	}

	Inorder(temp->left); 
	cout<<temp->data<<" "; 
	Inorder(temp->right);
}

void inOrder(struct node *root)
{
	stack<node *> s; 
	node *curr = root;

	while (curr != NULL || s.empty() == false)
	{
		while (curr !=  NULL)
		{
			s.push(curr); curr = curr->left;
		}
	curr = s.top();
	s.pop();
	cout << curr->data << " "; curr = curr->right;
	}
}

void postOrder(struct node* root)
{
	if (root == nullptr){ 
		return;
	}
	stack<node*> s; 
	s.push(root); 
	stack<int> out; 
	while (!s.empty())
	{
		node* curr = s.top(); 
		s.pop(); out.push(curr->data); 
		if (curr->left) {
			s.push(curr->left);
		}

		if (curr->right) { 
		s.push(curr->right);
		}
	}
	while (!out.empty())
	{
		cout << out.top() << " "; 
		out.pop();
	}
}

void preOrder(struct node* root){ 
	if (root == NULL){
		return;
	}
	stack<node*> st; 
	node* curr = root;
	while (!st.empty() || curr != NULL) { 
		while (curr != NULL) {
			cout << curr->data << " ";
			if (curr->right){
				st.push(curr->right);
			}
		curr = curr->left;
		}
		if (st.empty() == false) 
		{ 
		curr = st.top(); st.pop();
		}
	}
}

void Postorder(node *temp){
	if (temp==NULL) return;
	Postorder(temp->left); 
	Postorder(temp->right); 
	cout<<temp->data<<" ";
}

void Preorder(node *temp){
	if(temp==NULL) return;
	cout<<temp->data<<" "; 
	Preorder(temp->left); 
	Preorder(temp->right);
}

int main()
{
	struct node* root = createNode(4); 
	root->left = createNode(3);
	root->right = createNode(5);
	root->left->left = createNode(15); 
	root->left->right = createNode(11); 
	root->left->left->left = createNode(7);
	root->left->left->right = createNode(2); 
	root->right->left = createNode(14); 
	root->right->right = createNode(20);
	root->right->right->left = createNode(25); 
	root->right->right->right = createNode(9);
	int ch,p=1; 
	while(p==1){
		cout<<"\n====MENU===="<<endl; cout<<"1) Inorder Transverse "<<endl; cout<<"2) Postorder Transverse "<<endl; cout<<"3) Preorder Transverse \n"<<endl; cin>>ch;
		switch(ch){ 
			case 1:
				cout<<"1) Inorder with recursion: "<<endl; 
				cout<<"2) Inorder without recursion: "<<endl;
				cout<<endl;
				int ch1; 
				cin>>ch1; 
				switch(ch1){ 
					case 1:
						Inorder(root); 
						cout<<endl; 
						break;
					case 2:
						inOrder(root); 
						cout<<endl; 
						break;
					default:
						cout<<"Enter a valid expression. "<<endl; 
						break;
				}
				break;

			case 2:
				cout<<"1) Postorder with recursion. "<<endl; 
				cout<<"2) Postorder without recursion. "<<endl;
				cout<<endl;
				int ch2; 
				cin>>ch2; 
				switch(ch2){ 
					case 1:
						Postorder(root); 
						break;
					case 2:
						postOrder(root);
						break; 
					default:
						cout<<"Enter a valid expression. "<<endl; 
						break;
					}
					cout<<endl; 
					break;

			case 3:
				cout<<"1) Preorder with recursion. "<<endl; 
				cout<<"2) Preorder without recursion. "<<endl;
				cout<<endl;
				int ch3;
				cin>>ch3; 
				switch(ch3){ 
					case 1:
						Preorder(root); 
						break;
					case 2:
						preOrder(root); 
						break;
					default:
						cout<<"Enter a valid expression. "<<endl; 
						break;
				}
				break;

			default:
				cout<<"Enter a valid expression. "<<endl; 
				break;

		}
	}
	cout<<"\n\nPress 1 to continue\n"; 
	cin>>p;
}

