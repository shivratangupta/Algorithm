#include<iostream>
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

void sumRootToLeaf(TreeNode*root, int sum, int &totalSum){
	if(root == NULL)
		return;

	if(root->left == NULL && root->right == NULL){
		sum = sum * 10 + root->val;
		totalSum += sum;
		return;
	}

	sum = sum * 10 + root->val;
	sumRootToLeaf(root->left, sum, totalSum);
	sumRootToLeaf(root->right, sum, totalSum);
}

int sumNumbers(TreeNode* root){
	int sum, totalSum;
	sum = 0;
	totalSum = 0;

	sumRootToLeaf(root, sum, totalSum);

	return totalSum;
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

	int result;
	result = sumNumbers(root);

	cout<<result;
}