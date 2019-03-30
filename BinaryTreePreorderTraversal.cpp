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

vector<int> preorderTraversal(TreeNode* root){
	vector<int> result, a, b;
	if(root == NULL)
		return result;

	result.push_back(root->val);

	a = preorderTraversal(root->left);
	b = preorderTraversal(root->right);

	for(int i=0; i<a.size(); i++)
		result.push_back(a[i]);

	for(int i=0; i<b.size(); i++)
		result.push_back(b[i]);

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

	vector<int> result;
	result = preorderTraversal(root);

	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<"\t";
}