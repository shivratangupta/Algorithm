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

int maxpathsum(TreeNode* root, int &result){
	if(root == NULL)
		return 0;

	int ls, rs;

	ls = max(0, maxpathsum(root->left, result));
	rs = max(0, maxpathsum(root->right, result));

	result = max(result, ls + rs + root->val);

	return max(ls, rs) + root->val;
}

int maxPathSum(TreeNode* root){
	int result, a;
	result = INT_MIN;

	a = maxpathsum(root, result);

	result = max(result, a);

	return result;
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
	result = maxPathSum(root);

	cout<<result;
}
