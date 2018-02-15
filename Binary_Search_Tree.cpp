#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* root;

Node* newnode(int n){
	Node* temp = new Node();
	temp->data = n;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

Node* Insert(Node* root, int n){
	if(root == NULL){
		root = newnode(n);
	}
	
	else if(n <= root->data){
		root->left = Insert(root->left, n);
	}
	
	else{
		root->right = Insert(root->right, n);
	}
}

void Search(Node* root, int n){
	if(root == NULL){
		cout<<"Not Found"<<endl;
	}
	
	else if(root->data == n){
		cout<<"Found"<<endl;
	}
	
	else if(n <= root->data){
		Search(root->left, n);
	}
	
	else{
		Search(root->right, n);
	}
}

void Min(){
	Node* temp;
	temp = root;
	
	if(temp == NULL){
		cout<<"Tree is empty"<<endl;
	}
	
	else{
		while(temp->left != NULL){
			temp = temp->left;
		}
		
		cout<<"Minimum no. in tree is:"<<temp->data<<endl;
	}
}

void Max(){
	Node* temp;
	temp = root;
	
	if(temp == NULL){
		cout<<"Tree is empty"<<endl;
	}
	
	else{
		while(temp->right != NULL){
			temp = temp->right;
		}
		
		cout<<"Maximum no. in tree is:"<<temp->data<<endl;
	}
}

int Height(Node* root){
	int leftheight, rightheight;
	if(root == NULL){
		return -1;
	}
	
	else{
		leftheight = Height(root->left);
		rightheight = Height(root->right);
		
		return max(leftheight, rightheight) + 1;
	}
}

void Levelordertraversal(Node* root){
	if(root == NULL){
		cout<<"Tree is empty"<<endl;
	}
	
	else{
		queue<Node*> q;
		q.push(root);
		
		while(!q.empty()){
			Node* current;
			current = q.front();
			
			if(current->left != NULL)
				q.push(current->left);
				
			if(current->right != NULL)
				q.push(current->right);
				
			cout<<current->data<<"\t";
			q.pop();
		}
		
		cout<<endl;
	}
}

void Preordertraversal(Node* root){
	if(root == NULL){
		return;
	}
	
	else{
		cout<<root->data<<"\t";
		Preordertraversal(root->left);
		Preordertraversal(root->right);
	}
}

void Inordertraversal(Node* root){
	if(root == NULL){
		return;
	}
	
	else{
		Inordertraversal(root->left);
		cout<<root->data<<"\t";
		Inordertraversal(root->right);
	}
}

void Postordertraversal(Node* root){
	if(root == NULL){
		return;
	}
	
	else{
		Postordertraversal(root->left);
		Postordertraversal(root->right);
		cout<<root->data<<"\t";
	}
}

int main(){
	root = NULL;
	
	int choice, n, height;
	
	while(1){
		cout<<"1.Insert"<<endl;
		cout<<"2.Search"<<endl;
		cout<<"3.Min"<<endl;
		cout<<"4.Max"<<endl;
		cout<<"5.Height"<<endl;
		cout<<"6.Level Order Traversal"<<endl;
		cout<<"7.Pre Order Traversal"<<endl;
		cout<<"8.In Order Traversal"<<endl;
		cout<<"9.Post Order Traversal"<<endl;
		cout<<"10.Exit"<<endl;
		
		cout<<"Enter choice:";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter data:";
				cin>>n;
				root = Insert(root, n);
				break;
				
			case 2:
				cout<<"Enter data which you want to search:";
				cin>>n;
				Search(root, n);
				break;
				
			case 3:
				Min();
				break;
				
			case 4:
				Max();
				break;
				
			case 5:
				height = Height(root);
				cout<<"Height of the tree is:"<<height<<endl;
				break;
				
			case 6:
				Levelordertraversal(root);
				break;
				
			case 7:
				Preordertraversal(root);
				cout<<endl;
				break;
				
			case 8:
				Inordertraversal(root);
				cout<<endl;
				break;
				
			case 9:
				Postordertraversal(root);
				cout<<endl;
				break;
				
			case 10:
				exit(0);
				break;
				
			default:
				cout<<"You have entered wrong input"<<endl;
				break;
		}
	}
}
