#include<iostream>
#include<limits.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* newTreeNode(TreeNode* root, int num){
	if(root == NULL){
		TreeNode* temp = new TreeNode();
		temp->val = num;
		temp->left = NULL;
		temp->right = NULL;

		return temp;
	}

	else if(num < root->val)
		root->left = newTreeNode(root->left, num);

	else
		root->right = newTreeNode(root->right, num);

	return root;
}

bool isBST(TreeNode* root, int min, int max){
	if(root == NULL)
		return true;

	if(root->val == INT_MIN && root->left != NULL)
		return false;
		
	if(root->val == INT_MAX && root->right != NULL)
		return false;

	if(root->val < min || root->val > max)
		return false;

	return isBST(root->left, min, root->val - 1) && isBST(root->right, root->val + 1, max);
}

bool isValidBST(TreeNode* root){
	
	return isBST(root, INT_MIN, INT_MAX);	
}

int main(){
	TreeNode* root;
	root = NULL;

	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		int num;
		cin>>num;

		root = newTreeNode(root, num);
	}

	bool result;
	result = isValidBST(root);

	cout<<result;
}
