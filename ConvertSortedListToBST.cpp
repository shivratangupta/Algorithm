#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

ListNode* newListNode(ListNode* head, int num){
	ListNode* temp = new ListNode();
	temp->val = num;
	temp->next = NULL;

	if(head == NULL)
		head = temp;

	else{
		ListNode* temp1;
		temp1 = head;

		while(temp1->next != NULL)
			temp1 = temp1->next;

		temp1->next = temp;
	}

	return head;
}

TreeNode* cbst(vector<ListNode*> &arr, int start, int end){
	if(start > end)
		return NULL;

	int mid;
	mid = (start + end) / 2;

	TreeNode* temp = new TreeNode();
	temp->val = arr[mid]->val;

	temp->left = cbst(arr, start, mid - 1);
	temp->right = cbst(arr, mid + 1, end);

	return temp;
}

TreeNode* sortedListToBST(ListNode* head){
	if(head == NULL)
		return NULL;

	vector<ListNode*> arr;

	ListNode* temp;
	temp = head;
	while(temp != NULL){
		arr.push_back(temp);
		temp = temp->next;
	}

	return cbst(arr, 0, arr.size() - 1);
}

void inOrder(TreeNode* root){
	if(root == NULL)
		return;

	inOrder(root->left);
	cout<<root->val<<"\t";
	inOrder(root->right);
}

int main(){
	ListNode* head;
	head = NULL;

	TreeNode* root;
	root = NULL;

	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		int num;
		cin>>num;

		head = newListNode(head, num);
	}

	root = sortedListToBST(head);

	inOrder(root);
}