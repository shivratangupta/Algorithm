#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Node{
	int data;
	Node* link;
};

Node* top = NULL;

void Push(){
	Node* temp = new Node();
	cout<<"Enter data:";
	cin>>temp->data;
	temp->link = top;
	top = temp;
}

void Pop(){
	if(top == NULL){
		cout<<"Error: Stack Underflow"<<endl;
	}
	
	else{
		Node* temp;
		temp = top;
		
		top = temp->link;
		delete temp;
	}
}

void Top(){
	if(top == NULL){
		cout<<"Stack is empty"<<endl;
	}
	
	else{
		cout<<top->data<<endl;
	}
}

void Isempty(){
	if(top == NULL){
		cout<<"True"<<endl;
	}
	
	else{
		cout<<"False"<<endl;
	}
}

int main(){
	int choice;
	
	while(2>1){
		cout<<"1.Push"<<endl;
		cout<<"2.Pop"<<endl;
		cout<<"3.Top"<<endl;
		cout<<"4.Isempty"<<endl;
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
				Top();
				break;
				
			case 4:
				Isempty();
				break;
				
			case 5:
				exit(0);
				break;
			
			default:
				cout<<"You have entered wrong input"<<endl;
				break;
		}
	}
}
