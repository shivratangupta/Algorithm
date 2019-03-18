#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* newTreeNode(TreeNode* root, int num){
	if(root == NULL || root->val == num){
		TreeNode* temp = new TreeNode();
		temp->val = num;
		temp->left = NULL;
		temp->right = NULL;

		root = temp;

		return root;
	}

	else if(num < root->val)
		root->left = newTreeNode(root->left, num);

	else
		root->right = newTreeNode(root->right, num);

	return root;
}

vector<int> inorderTraversal(TreeNode* root){
	vector<int> a;
	vector<int> b;

	if(root == NULL)
		return a;

	a = inorderTraversal(root->left);
	a.push_back(root->val);
	b = inorderTraversal(root->right);

	for(int i=0; i<b.size(); i++)
		a.push_back(b[i]);

	return a;
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
	result = inorderTraversal(root);

	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<"\t";
}
