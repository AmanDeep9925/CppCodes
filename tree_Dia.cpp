// diameter of the binary tree
#include "Btree.h"
#include <iostream>
using namespace std;

int diameter(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftdia = diameter(root->left);
	int rightdia = diameter(root->right);

	int curdia = Btree_height(root->left) + 1 + Btree_height(root->right);

	return max(curdia, max(leftdia, rightdia));
}

int main()
{
	Node* root = creatree();
	preorder(root);
	int ans = diameter(root);

	cout << ans;
}