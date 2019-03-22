#include<iostream>
#include<stdlib.h>
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

int depth(TreeNode* root){
	if(root == NULL)
		return 0;

	return 1 + max(depth(root->left), depth(root->right));
}

bool isBalanced(TreeNode* root){
	if(root == NULL)
		return true;

	int hl, hr;
	bool flag;
	flag = false;

	hl = depth(root->left);
	hr = depth(root->right);

	if(abs(hl - hr) < 2)
		flag = true;

	return flag && isBalanced(root->left) && isBalanced(root->right);
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
	result = isBalanced(root);

	cout<<result;
}
