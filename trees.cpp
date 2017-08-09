#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	int nchild;
	Node** childArr;

	Node(int d,int n)
	{
		data=d;
		nchild=n;
		if(n==0)
		{
			childArr = NULL;
		}
		else
		{
			childArr = new Node*[nchild];
		}
	}
};

Node* createtree()
{
	int d;
	cin>>d;
	if(d==-1)
	{
		return NULL;
	}
	int N;
	cin>>N;
	Node* root = new Node(d,N);
	for (int i = 0; i < root->nchild; ++i)
	{
		root->childArr[i]= createtree();
	}

	return root;
}

void printtree(Node* root)
{
	if(root == NULL)
	{
		return ;
	}
	else
		cout<<root->data;
	for (int i = 0; i < root->nchild; ++i)
	{
		printtree(root->childArr[i]);
	}
}

int main()
{
	Node * tree=NULL;
	tree= createtree();
	printtree(tree);
}