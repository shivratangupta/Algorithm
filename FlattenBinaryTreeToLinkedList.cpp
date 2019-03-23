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

void flatten(TreeNode* root){
	if(root == NULL)
		return;

	TreeNode* temp;
	temp = root;

	while(temp != NULL){
		if(temp->left != NULL){
			TreeNode* righttree;
			righttree = temp->left;

			while(righttree->right != NULL)
				righttree = righttree->right;

			righttree->right = temp->right;
			temp->right = temp->left;
			temp->left = NULL;
		}

		temp = temp->right;
	}
}

void preOrder(TreeNode* root){
	if(root == NULL)
		return;

	cout<<root->val<<"\t";
	
	preOrder(root->left);
	preOrder(root->right);
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

	flatten(root);

	preOrder(root);
}
