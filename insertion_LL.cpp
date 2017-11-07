#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};

Node* createNode(int n)
{
	Node* ptr= new Node;
	ptr->data=n;
	ptr->next = NULL;
	return ptr;
}

Node* insertNode(Node* head)
{
	Node* temp = new Node;
	if(head==NULL)
	{
		return temp;
	}
	else
	{	temp->next = head;
		return temp;
	}
}

void printLL(Node* head)
{
	Node* cur = head;
	while(head)
	{
		cout<<cur->data<<" ";
		cur= cur->next;
	}
}