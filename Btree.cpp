#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int D)
	{
		data = D;
		left = NULL;
		right = NULL;
	}
};

Node* creatree()
{
	int d;
	cin >> d;
	if (d == -1)
	{
		return NULL;
	}
	Node* root = new Node(d);
	root->left = creatree();
	root->right = creatree();
	return root;
}

void preorder(Node* root)
{
	if (root == NULL)
	{
		return ;
	}

	cout << root->data << " " ;
	preorder(root->left);
	preorder(root->right);
}

int main()
{
	Node* root = creatree();
	preorder(root);
}