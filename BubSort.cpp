#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(int X)
	{
		data = X;
		next = NULL;
	}
};

Node* insert(Node* head, int d) {
	Node* tmp = new Node(d);

	if (head == NULL) {
		//empty list
		return tmp;
	}

	// (*tmp).next = head;
	tmp->next = head;
	return tmp;
}


Node* createList() {
	Node * head = NULL;
	int x;

	while (true) {
		cin >> x;
		if (x == - 1) break;
		head = insert(head, x);
	}
	return head;
}

void printLL(Node* head) {
	Node * cur = head;
	while (cur != NULL) {
		cout << cur->data << "-->";
		cur = cur->next;	//take cur to the next element
	}
	cout << endl;
}

int lengthLL(Node * head) {
	int cnt = 0;
	while (head) {
		++cnt;
		head = head->next;
	}
	return cnt;
}

void bubbleSort(Node* &head) {
	int len = lengthLL(head);

	for (int i = 0; i < len; ++i) {
		Node * cur = head;
		Node * prev = NULL;

		// Node * ahead = cur->next;	it is not guaranteed that cur is NOT null
		while (cur && cur->next) {
			Node* ahead = cur->next;	//cur is guranteed NOT to be NULL

			if (cur->data > ahead->data) {
				// swap the nodes
				if (prev == NULL) {
					head = ahead;	//to keep track of head

					cur->next = ahead->next;
					ahead->next = cur;
					prev = ahead;
					ahead = cur->next;
				}
				else {
					//when prev is NOT null
					prev->next = ahead;
					cur->next = ahead->next;
					ahead->next = cur;
					prev = ahead;
					ahead = cur->next;

				}
			}
			else {
				prev = cur;
				cur = ahead;
				ahead = cur->next;	//ahead will be destroyed so can be avoided! But improves logic
			}
		}
	}

}

int main()
{
	Node * head = NULL;
	head = createList();
	printLL(head);

	bubbleSort(head);
	printLL(head);
}
