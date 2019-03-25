#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
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
	if(root == NULL)
		return;

	TreeNode* prev = new TreeNode();
	prev->val = INT_MIN;
	prev->left = NULL;
	prev->right = NULL;
	prev->next = NULL;

	TreeNode *temp, *curr;
	curr = root;
	temp = prev;

	while(curr != NULL){
		if(curr->left != NULL){
			temp->next = curr->left;
			temp = temp->next;
		}

		if(curr->right != NULL){
			temp->next = curr->right;
			temp = temp->next;
		}

		curr = curr->next;
	}

	connect(prev->next);
}

vector<vector<int> > levelOrderTraversal(TreeNode* root){
	vector<vector<int> > result;

	if(root == NULL)
		return result;

	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()){
		int n;
		n = q.size();

		vector<int> arr;
		while(n > 0){
			TreeNode* temp;
			temp = q.front();
			arr.push_back(temp->val);

			if(temp->left != NULL)
				q.push(temp->left);

			if(temp->right != NULL)
				q.push(temp->right);

			q.pop();
			n--;
		}

		result.push_back(arr);
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
	result = levelOrderTraversal(root);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++){
			cout<<result[i][j]<<"\t";
		}

		cout<<endl;
	}
}
