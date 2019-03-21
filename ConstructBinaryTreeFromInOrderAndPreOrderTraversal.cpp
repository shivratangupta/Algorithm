#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* cbst(vector<int> &pre, int ps, int pe, vector<int> &in, int is, int ie){
	if(is > ie)
		return NULL;

	TreeNode* temp = new TreeNode();
	temp->val = pre[ps];
	temp->left = NULL;
	temp->right = NULL;

	int j;
	for(j=is; j<=ie; j++){
		if(in[j] == temp->val)
			break;
	}

	if(j != is)
		temp->left = cbst(pre, ps + 1, ps + j - is, in, is, j - 1);

	if(j != ie)
		temp->right = cbst(pre, ps + j - is + 1, pe, in, j + 1, ie);

	return temp;
}

void preOrder(TreeNode* root){
	if(root == NULL)
		return;

	cout<<root->val<<"\t";

	preOrder(root->left);
	preOrder(root->right);
}

TreeNode* buildTree(vector<int> &pre, vector<int> &in){

	return cbst(pre, 0, pre.size() - 1, in, 0, in.size() - 1);
}

int main(){
	TreeNode* root;
	root = NULL;

	int n;
	cin>>n;

	vector<int> pre;
	vector<int> in;

	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		pre.push_back(num);
	}

	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		in.push_back(num);
	}

	root = buildTree(pre, in);

	preOrder(root);
}
