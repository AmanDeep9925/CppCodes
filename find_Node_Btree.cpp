#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

Node* createTREE()
{
	int d;
	cin >> d;
	if (d == -1)
	{
		return NULL;
	}
	else

	{
		Node* root = new Node(d);
		root->left = createTREE();
		root->right = createTREE();
		return root;
	}
}

Node* find_Node(Node* root, int val)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == val)
	{
		return root;
	}
	Node* lftans = find_Node(root->left, val);
	if (lftans) return lftans;

	return find_Node(root->right, val);
}

void postorder(Node* root)
{
	if (root == NULL)
	{
		return ;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}
int main()
{
	Node* root = NULL;
	root = createTREE();
	postorder(root);
	int ele;
	cin >> ele;
	Node* ans = find_Node(root, ele);
	cout << ans << " " << ans->data;

}