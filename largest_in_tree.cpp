#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	int nchild;
	Node** childArr;

	Node(int d, int N)
	{
		data = d;
		nchild = N;
		if (N == 0)
		{
			childArr = NULL;
		}
		else
		{
			childArr = new Node*[nchild];
		}
	}
};

Node* CreateTree()
{
	int D;// declaring variable to store parent's data;
	cin >> D;

	if (D == -1)
	{
		return NULL;
	}

	int child;
	cin >> child;
	Node * root = new Node(D, child);

	for (int i = 0; i < root->nchild; ++i)
	{
		root->childArr[i] = CreateTree();
	}

	return root;
}

int findlargest(Node* root)
{
	static const int inf = 100000;
	if (root == NULL)
	{
		return -inf;
	}
	int result = root->data;
	for (int i = 0; i < root->nchild; ++i)
	{
		int chilaAns = findlargest(root->childArr[i]);
		result = max(result, chilaAns);
	}

	return result;
}

int main()
{
	Node* root = NULL;
	root = CreateTree();

	int ans = findlargest(root);

	cout << "largest of the tree is : " << ans;
}