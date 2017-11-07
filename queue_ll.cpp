// IMPLEMENTING THE QUEUE AS LINKED LIST

#include <iostream>
using namespace std;
// NODE OF THE QUEUE
struct Node
{
	Node * next;
	int data;
};

class Queue
{
public:
	Node *front, *rear;
	Queue()
	{
		front = NULL;
		rear = NULL;
	}

	bool empty()
	{
		if (front == NULL && rear == NULL)
		{
			return true;
		}
		else return false;
	}
// ADDING ELEMENT IN THE QUEUE
	void QueueIN(int N)
	{	// CREATING THE THE NEW NODE
		Node * temp = new Node;
		// SETTING UP THE DATA TO THE PASSED VALUE
		temp->data = N;
		// POINTING TO NULL
		temp->next = NULL;
		if (front == NULL && rear == NULL)
		{	// IF THIS NODE IS THE FIRST NODE OF THE QUEUE
			front = rear = temp;
		}
		else
		{
			rear->next = temp;
			rear = temp;
			rear->next = NULL;
		}
	}
// CURRENT ELEMENT IN THE QUEUE IS EXECUTED HENCE MOVE TO FORWARD
	void QueueOut()
	{
		Node* temp = front;
		// IF THE QUEUE IS STILL EMPTY
		if (empty())
		{
			return ;
		}
		else
		{	// GETTING THE CURRENT HEAD ELEMENT
			temp = front;
			// SETTING THE NEXT ELEMENT TO THE FRONT ELEMENT
			front = front->next;
		}
		// DELETING THE TEMPROARY ELEMENT
		delete temp;
	}
// show the queue
	void showQueue()
	{	// IF THE QUEUE IS STILL EMPTY
		if (!empty())
		{
			cout << front->data;
		}
		return ;
	}
};

// MAIN FUNCTION OF THE PROGRAM

int main()
{
	Queue Q;

	Q.QueueIN(5);
	Q.QueueIN(4);
	Q.QueueIN(3);
	Q.QueueIN(2);
	Q.showQueue();
	Q.QueueOut();
	Q.showQueue();
	Q.QueueOut();
	Q.showQueue();
	Q.QueueOut();
	Q.showQueue();
	Q.QueueOut();

}