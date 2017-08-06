#include <iostream>
using namespace std;

class Stack
{
	int * Arr;
	int top_ind;
public:
	Stack()
	{
		Arr = new int[100];
		top_ind = -1;
	}

	~Stack()
	{
		delete [] Arr;
	}

	bool empty()
	{
		return top_ind == -1;
	}

	int Stack_Size()
	{
		return top_ind + 1;
	}

	void push_in(int N)
	{
		if (top_ind < 100)
		{
			++top_ind;
			Arr[top_ind] = N;
		}
	}

	void pop()
	{
		if (empty()) return;
		--top_ind;
	}

	int Top_ind()
	{
		if (!empty())
		{
			return Arr[top_ind];
		}
		return -1;
	}
};

int main()
{
	int N;
	cin >> N; // how mant number you want to entet in the stack
	Stack S;
	for (int i = 0; i < N; ++i)
	{
		int X;
		cin >> X;
		S.push_in(X);
	}

	for (int i = 0; i < N; ++i)
	{
		cout << S.Top_ind() << " ";
		S.pop();
	}
}