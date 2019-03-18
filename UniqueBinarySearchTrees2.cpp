#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* newTreeNode(int num){
	TreeNode* temp = new TreeNode();
	temp->val = num;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void preorder(TreeNode* root){
	if(root == NULL)
		return;

	cout<<root->val<<"\t";
	preorder(root->left);
	preorder(root->right);
}

vector<TreeNode*> generateBST(int s, int e){
	vector<TreeNode*> result;

	if(s > e){
		result.push_back(NULL);
		return result;
	}

	for(int i=s; i<=e; i++){
		vector<TreeNode*> leftsub;
		vector<TreeNode*> rightsub;

		leftsub = generateBST(s, i - 1); 
		rightsub = generateBST(i + 1, e);

		for(int j=0; j<leftsub.size(); j++){
			TreeNode* left;
			left = leftsub[j];

			for(int k=0; k<rightsub.size(); k++){
				TreeNode* right;
				right = rightsub[k];

				TreeNode* Node;
				Node = newTreeNode(i);

				Node->left = left;
				Node->right = right;

				result.push_back(Node);
			}
		}
	}

	return result;
}

vector<TreeNode*> generateTrees(int n){
	vector<TreeNode*> result;

	if(n == 0)
		return result;

	result = generateBST(1, n);

	return result;
}

int main(){
	int n;
	cin>>n;

	vector<TreeNode*> result;
	result = generateTrees(n);

	for(int i=0; i<result.size(); i++){
		preorder(result[i]);
		cout<<endl;
	}
}
