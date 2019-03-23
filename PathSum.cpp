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

bool hasPathSum(TreeNode* root, int sum){
	if(root == NULL)
		return false;

	bool result;
	result = false;
	sum -= root->val;

	if(sum == 0 && root->left == NULL && root->right == NULL)
		return true;

	if(root->left != NULL)
		result = result || hasPathSum(root->left, sum);

	if(root->right != NULL)
		result = result || hasPathSum(root->right, sum);

	return result;
}

int main(){
	TreeNode* root;
	root = NULL;

	int n, sum;
	cin>>n;

	for(int i=0; i<n; i++){
		int num;
		cin>>num;

		root = newTreeNode(root, num);
	}

	cin>>sum;

	bool result;
	result = hasPathSum(root, sum);

	cout<<result;
}