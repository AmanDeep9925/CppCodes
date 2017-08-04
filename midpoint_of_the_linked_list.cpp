// IN THIS CODE WE ARE GOING TO FIND OUT THE MIDDLE ELEMENT OF THE LINKED LIST

#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node * next;
	Node(int D)
	{
		data = D;
		next = NULL;
	}
};

Node* Insert(Node* head, int N)
{
	Node* temp = new Node(N);

	if (head == NULL)
	{
		return temp;
	}
	else
	{
		temp->next = head;
	}
	return temp;
}

Node* createLL()
{
	Node* head = NULL;
	int X;
	while (true)
	{	cin >> X;
		if (X == -1) break;
		else
		{
			head = Insert(head, X);
		}
	}
	return head;
}

void Printll(Node* head)
{
	Node* cur = head;
	while (cur != NULL)
	{
		cout << cur->data << "-->";
		cur = cur->next;
	}
}

Node* mid_Point(Node* head)
{
	Node* slow = head;
	Node* fast = head;
	while (slow && fast && slow->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

int main()
{
	Node* head = NULL;

	head = createLL();

	Printll(head);

	Node* mid = mid_Point(head);

	cout << "\n" << mid << " " << (mid ? mid->data : -1) << endl;
}

