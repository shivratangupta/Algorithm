#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* next;
};

TreeNode* newTreeNode(TreeNode* root, int num){
	if(root == NULL){
		TreeNode* temp = new TreeNode();
		temp->val = num;
		temp->left = NULL;
		temp->right = NULL;
		temp->next = NULL;

		return temp;
	}

	else if(num < root->val)
		root->left = newTreeNode(root->left, num);

	else
		root->right = newTreeNode(root->right, num);

	return root;
}

void connect(TreeNode* root){
	if(root == NULL || root->left == NULL && root->right == NULL)
		return;

	TreeNode *temp, *temp1;
	temp = root->left;
	temp1 = root->right;
	temp->next = temp1;

	while(temp->right != NULL){
		temp = temp->right;
		temp1 = temp1->left;
		temp->next = temp1;
	}

	connect(root->left);
	connect(root->right);
}

vector<vector<int> > traversal(TreeNode* root){
	vector<vector<int> > result;

	if(root == NULL)
		return result;

	TreeNode* temp;
	temp = root;

	while(temp != NULL){
		vector<int> arr;

		TreeNode* temp1;
		temp1 = temp;

		while(temp1 != NULL){
			arr.push_back(temp1->val);
			temp1 = temp1->next;
		}

		result.push_back(arr);
		temp = temp->left;
	}

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

	connect(root);

	vector<vector<int> > result;
	result = traversal(root);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++){
			cout<<result[i][j]<<"\t";
		}

		cout<<endl;
	}
}
