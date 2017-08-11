#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	int nchild;
	Node** childarr;
	Node(int D,int N)
	{
		data = D;
		nchild = N;
		if(N==0)
		{
			childarr = NULL;
		}
		else
		{
			childarr = new Node*[nchild];
		}
	}
};

Node* createTree()
{
	int D;
	cin>>D;
	if(D==-1)
	{
		return NULL;
	}

	int N;
	cin>>N;
	Node* root = new Node(D,N);

	for (int i = 0; i < root->nchild; ++i)
	{
		root->childarr[i] = createTree(); 
	}
	return root;
}

void postorder(Node* root)
{
	if(root == NULL)
	{
		return ;
	}

	for (int i = 0; i < root->nchild; ++i)
	{
		postorder(root->childarr[i]);
	}

	cout << root->data<<" ";
}

int main()
{
	Node *root = NULL;
	root = createTree();
	postorder(root);
}