#include <iostream>
using namespace std;

class Node
{

public:
	Node *next;
	int Data;
	Node(int n)
	{
		Data = n;
		next = NULL;
	}
};

// this function will add a node to our head list

Node * insert(Node *head, int val)
{
	Node *temp = new Node(val);

	// if this node is thge first node
	//i.e the head is still empty so
	if (head == NULL)
	{
		return temp;
	}
	else
		temp->next = head;
	return temp;
}

// now let's print our list

void printll(Node * head)
{
	// this fnc will simply do that it is
	// printing our list data
	Node * cur = head;
	while (cur) // upto when cur exist
	{
		cout << cur->Data<<"-->";
		cur = cur->next; // this next pointer will movw cur to next node
	}
}

Node * createll(int N)
{	// N here represent how much values do yo want to enter
	Node* head = NULL;
	for (int i = 0; i < N; ++i)
	{	int x;
		cin >> x;
		head = insert(head, x);
	}
	return head;
}


Node * searchll(Node *head, int N)
{
	if (head == NULL)
	{
		return NULL;
	}
	if (head->Data == N)
	{
		return head;
	}

	return searchll(head->next, N);
}

int main()
{
	Node * head = NULL;
	int N;
	cin>>N;
	head = createll(N);
	printll(head);
	int x;
	cin>>x;
	Node* search = searchll(head,N);
	cout << search;
	if (search != NULL) cout << search->Data << endl;
}