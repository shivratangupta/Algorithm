#include<iostream>
#include<vector>
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

bool isSameTree(TreeNode* root1, TreeNode* root2){
	if(root1 == NULL && root2 == NULL)
		return true;

	if(root1 != NULL && root2 == NULL)
		return false;

	if(root1 == NULL && root2 != NULL)
		return false;

	if(root1->val == root2->val)
		return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);

	return false;
}

int main(){
	TreeNode* root1;
	root1 = NULL;

	int n1, n2;
	cin>>n1;

	for(int i=0; i<n1; i++){
		int num;
		cin>>num;

		root1 = newTreeNode(root1, num);
	}

	TreeNode* root2;
	root2 = NULL;

	cin>>n2;

	for(int i=0; i<n2; i++){
		int num;
		cin>>num;

		root2 = newTreeNode(root2, num);
	}

	bool result;
	result = isSameTree(root1, root2);

	cout<<result;
}
