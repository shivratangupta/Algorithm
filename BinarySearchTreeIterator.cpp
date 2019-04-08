#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

stack<TreeNode*> s;

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

int next(){
	TreeNode* temp;
	temp = s.top();
	s.pop();

	if(temp->right != NULL){
		TreeNode* temp1;
		temp1 = temp->right;
		while(temp1 != NULL){
			s.push(temp1);
			temp1 = temp1->left;
		}
	}

	return temp->val;
}

bool hasNext(){
	if(s.empty())
		return false;

	return true;
}

int main(){
	TreeNode* root;
	root = NULL;

	int n, choice;
	cin>>n;

	for(int i=0; i<n; i++){
		int num;
		cin>>num;

		root = newTreeNode(root, num);
	}

	while(root != NULL){
		s.push(root);
		root = root->left;
	}

	while(1){
		cout<<"1. next"<<endl;
		cout<<"2. hasNext"<<endl;
		cout<<"3. Exit"<<endl;

		cout<<"Enter choice:";
		cin>>choice;

		switch(choice){
			case 1:
				cout<<next()<<endl;
				break;

			case 2:
				cout<<hasNext()<<endl;
				break;

			case 3:
				exit(0);
				break;

			default:
				cout<<"You have entered wrong input"<<endl;
				break;
		}
	}
}
