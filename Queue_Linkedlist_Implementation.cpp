#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* front;
Node* rear;

void Push(){
	Node* temp = new Node();
	cout<<"Enter data:";
	cin>>temp->data;
	temp->next = NULL;
	
	if(front == NULL && rear == NULL){
		front = temp;
		rear = temp;
	}
	
	else{
		rear->next = temp;
		rear = temp;
	}
}

void Pop(){
	if(front == NULL && rear == NULL){
		cout<<"Queue is empty"<<endl;
	}
	
	else if(front == rear){
		front == NULL;
		rear == NULL;
	}
	
	else{
		Node* temp;
		temp = front;
		front = front->next;
		delete temp;
	}
}

void Front(){
	if(front == NULL && rear == NULL){
		cout<<"Queue is empty"<<endl;
	}
	
	else{
		cout<<front->data<<endl;
	}
}

void Isempty(){
	if(front == NULL && rear == NULL){
		cout<<"Queue is empty"<<endl;
	}
	
	else{
		cout<<"Queue is not empty"<<endl;
	}
}

int main(){
	front = NULL;
	rear = NULL;
	
	int choice;
	
	while(1){
		cout<<"1.Push"<<endl;
		cout<<"2.Pop"<<endl;
		cout<<"3.Front"<<endl;
		cout<<"4.Is Empty"<<endl;
		cout<<"5.Exit"<<endl;
		
		cout<<"Enter choice:";
		cin>>choice;
		
		switch(choice){
			case 1:
				Push();
				break;
				
			case 2:
				Pop();
				break;
				
			case 3:
				Front();
				break;
				
			case 4:
				Isempty();
				break;
				
			case 5:
				exit(0);
				break;
				
			default:
				cout<<"You have entered wrong input"<<endl;
		}	
	}
}
