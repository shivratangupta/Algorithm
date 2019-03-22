#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* cbst(vector<int> &nums, int start, int end){
	if(start > end)
		return NULL;

	int mid;
	mid = (start + end) / 2;

	TreeNode* temp = new TreeNode();
	temp->val = nums[mid];

	temp->left = cbst(nums, start, mid - 1);
	temp->right = cbst(nums, mid + 1, end);

	return temp; 
}

void inOrder(TreeNode* root){
	if(root == NULL)
		return;

	inOrder(root->left);
	cout<<root->val<<"\t";
	inOrder(root->right);
}

TreeNode* sortedArrayToBST(vector<int> &nums){

	return cbst(nums, 0, nums.size() - 1);
}

int main(){
	TreeNode* root;
	root = NULL;

	int n;
	cin>>n;

	vector<int> arr;
	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		arr.push_back(num);
	}

	root = sortedArrayToBST(arr);

	inOrder(root);
}