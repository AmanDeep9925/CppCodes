#include <iostream>
using namespace std;

struct Node
{
	Node* next;
	int data;
};

class stack
{
	Node* top;
	
public:
	stack()
	{
		top=NULL;
	}

	bool empty()
	{
		if(top==NULL)
		{
			
			return true;
		}
		else 
			{
			return false;
			}
}	

	void pushIn(int X)
	{
		Node* temp = new Node;
		temp->data = X;
		temp->next = NULL;
		if(top == NULL)
		{
			top = temp;
		}

		else 
			if(top!= NULL)
			{
				temp->next = top;
				top = temp;
			}
	}

	void pop()
	{
		Node* temp;
		temp=top;
		if(empty()) return;
		else
			top= top->next;
		delete temp;
	}

	void Top()
	{	if(!empty())
		{
		cout<<top->data<<" ";
		}
		return ;
	}
};


int main()
{
	stack S;
	S.pushIn(5);
	S.pushIn(6);
	S.Top();
	S.pop();
	S.Top();
	S.pop();
	S.Top();
}