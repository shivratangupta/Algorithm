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

int maxDepth(TreeNode* root){
	if(root == NULL)
		return 0;

	return 1 + max(maxDepth(root->left), maxDepth(root->right));
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
	result = maxDepth(root);

	cout<<result;
}
