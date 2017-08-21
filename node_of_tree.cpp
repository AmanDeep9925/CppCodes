#include <iostream>
#include "Btree.h"
using namespace std;

int cntnode(Node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int leftnode = cntnode(root->left);
	int rightnode = cntnode(root->right);
	int curnode = leftnode + 1 + rightnode;

	return curnode; 
}

int main()
{
	Node* root = creatree();
	int ans = cntnode(root);
	cout<<"\n ans "<< ans;
}