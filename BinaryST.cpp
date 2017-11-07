#include <iostream>
#include <queue>
using namespace std;

class BSTNode
{
public:
	int data;
	BSTNode* leftchild;
	BSTNode* rightchild;
	BSTNode(int d)
	{
		data = d;
		leftchild = NULL;
		rightchild = NULL;
	}

};

BSTNode* insert_in_BST(BSTNode * root, int val)
{
	if (root == NULL)
	{
		BSTNode* newNode = new BSTNode(val);
		return newNode;
	}

	if ( val < root->data)
	{
		BSTNode * updateTree = insert_in_BST(root->leftchild, val);
		root->leftchild = updateTree;

	}

	else
	{
		root->rightchild = insert_in_BST(root->rightchild, val);
	}

	return root;
}

BSTNode* createBST()
{
	int d;
	BSTNode* root = NULL;
	cin >> d; 
	while (d != -1)
	{
		root = insert_in_BST(root, d);
	}

	return root;
}

void inorder(BSTNode * root)
{
	if (root == NULL)
	{
		return;
	}

	inorder(root->leftchild);
	inorder(root->rightchild);
	cout << root->data;
}

void levelorder(BSTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	queue<BSTNode*> q;
	q.push(root);
	q.push(NULL);

	while (q.empty() == false)
	{
		BSTNode * cur = q.front();
		q.pop();

		if (cur == NULL)
		{
			cout << "\n ";
			if (!q.empty()) q.push(NULL);
			continue ;
		}
		cout << cur ->data << " ";

		if(cur->leftchild)
		{
			q.push(cur->leftchild);
		}

		if(cur->rightchild)
		{
			q.push(cur->rightchild);
		}

	}
}

int main()
{
	BSTNode * root = NULL;

	root = createBST();

	// inorder(root);
	levelorder(root);
}