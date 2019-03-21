#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
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

vector<vector<int> > zigzagLevelOrder(TreeNode* root){
	vector<vector<int> > result;

	if(root == NULL)
		return result;

	stack<TreeNode*> curr;
	stack<TreeNode*> next;
	curr.push(root);

	bool lefttoright;
	lefttoright = true;

	vector<int> arr;

	while(!curr.empty()){
		TreeNode* temp;
		temp = curr.top();
		curr.pop();
		arr.push_back(temp->val);

		if(lefttoright){
			if(temp->left != NULL)
				next.push(temp->left);

			if(temp->right != NULL)
				next.push(temp->right);
		}

		else{
			if(temp->right != NULL)
				next.push(temp->right);

			if(temp->left != NULL)
				next.push(temp->left);
		}

		if(curr.empty()){
			result.push_back(arr);
			arr.clear();
			lefttoright = !lefttoright;
			swap(curr, next);
		}
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

	vector<vector<int> > result;
	result = zigzagLevelOrder(root);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++){
			cout<<result[i][j]<<"\t";
		}

		cout<<endl;
	}
}
