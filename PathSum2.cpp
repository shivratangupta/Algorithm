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

void sumToLeaf(TreeNode* root, vector<vector<int> > &result, vector<int> &arr, int sum){
	if(sum == 0 && root->left == NULL && root->right == NULL){
		result.push_back(arr);
		return;
	}

	if(root->left != NULL){
		arr.push_back(root->left->val);
		sumToLeaf(root->left, result, arr, sum - root->left->val);
		arr.pop_back();
	}

	if(root->right != NULL){
		arr.push_back(root->right->val);
		sumToLeaf(root->right, result, arr, sum - root->right->val);
		arr.pop_back();
	}
}

vector<vector<int> > pathSum(TreeNode* root, int sum){
	vector<vector<int> > result;

	if(root == NULL)
		return result;

	vector<int> arr;
	arr.push_back(root->val);

	sumToLeaf(root, result, arr, sum - root->val);

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

	vector<vector<int> > result;
	result = pathSum(root, sum);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[0].size(); j++){
			cout<<result[i][j]<<"\t";
		}

		cout<<endl;
	}
}
