#include<iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

bool isMirror(TreeNode* root1, TreeNode* root2){
	if(root1 == NULL && root2 == NULL)
		return true;

	if(root1 != NULL && root2 != NULL && root1->val == root2->val)
		return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);

	return false;
}

bool isSymmetric(TreeNode* root){

	return isMirror(root, root);
}

int main(){
	TreeNode* root;
	root = NULL;

	bool result;
	result = isSymmetric(root);

	cout<<result;
}