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

vector<int> postorderTraversal(TreeNode* root){
	vector<int> result, a;

	if(root == NULL)
		return result;

	result = postorderTraversal(root->left);
	a = postorderTraversal(root->right);

	for(int i=0; i<a.size(); i++)
		result.push_back(a[i]);

	result.push_back(root->val);

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
	result = postorderTraversal(root);

	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<"\t";
}
