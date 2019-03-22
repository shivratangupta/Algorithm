#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

void inOrder(TreeNode* root){
	if(root == NULL)
		return;

	inOrder(root->left);
	cout<<root->val<<"\t";
	inOrder(root->right);
}

TreeNode* cbst(vector<int> &in, int is, int ie, vector<int> &post, int ps, int pe){
	if(is > ie)
		return NULL;

	TreeNode* temp = new TreeNode();
	temp->val = post[pe];
	temp->left = NULL;
	temp->right = NULL;

	int j;

	for(j=is; j<=ie; j++){
		if(in[j] == temp->val)
			break;
	}

	if(j != is)
		temp->left = cbst(in, is, j - 1, post, ps, ps + j - is - 1);

	if(j != ie)
		temp->right = cbst(in, j + 1, ie, post, ps + j - is, pe - 1);

	return temp;
}

TreeNode* buildTree(vector<int> &in, vector<int> &post){

	return cbst(in, 0, in.size() - 1, post, 0, post.size() - 1);
}

int main(){
	TreeNode* root;
	root = NULL;

	int n;
	cin>>n;

	vector<int> in;
	vector<int> post;

	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		in.push_back(num);
	}

	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		post.push_back(num);
	}

	root = buildTree(in, post);

	inOrder(root);
}
