#include<iostream>
#include<vector>
#include<queue>
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

	TreeNode *temp, *temp1;
	temp = root->left;
	temp1 = root->right;

	while(temp != NULL && temp1 != NULL){
		temp->next = temp1;
		if(temp->right != NULL)
			temp = temp->right;

		else
			temp = temp->left;

		if(temp1->left != NULL)
			temp1 = temp1->left;

		else
			temp1 = temp1->right;
	}

	connect(root->left);
	connect(root->right);
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
