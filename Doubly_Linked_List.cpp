#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node* prev;
};

Node* head;

void Insert(){
	Node* temp = new Node();
	cout<<"Enter data:";
	cin>>temp->data;
	temp->next = NULL;
	temp->prev = NULL;
	 
	if(head == NULL){
		head = temp;
	}
	
	else{
		Node* temp1;
		temp1 = head;
		
		while(temp1->next != NULL){
			temp1 = temp1->next;
		}
		
		temp1->next = temp;
		temp->prev = temp1;
	}
}

void Insert_node_at_beginning(){
	Node* temp = new Node();
	cout<<"Enter data:";
	cin>>temp->data;
	temp->next = NULL;
	temp->prev = NULL;
	
	if(head == NULL){
		head = temp;
	}
	
	else{
		temp->next = head;
		temp->next->prev = temp;
		head = temp;
	}
}

void Insert_node_at_nth_position(int n){
	Node* temp = new Node();
	cout<<"Enter data:";
	cin>>temp->data;
	temp->next = NULL;
	temp->prev = NULL;
	
	if(n == 1){
		temp->next = head;
		temp->next->prev = temp;
		head = temp;
	}
	
	else{
		Node* temp1;
		temp1 = head;
		
		for(int i=0; i<n-2; i++){
			temp1 = temp1->next;
		}
		
		temp->next = temp1->next;
		temp1->next->prev = temp;
		temp1->next = temp;
		temp->prev = temp1;
	}
}

void Delete_node_at_nth_position(int n){
	
	if(head == NULL){
		cout<<"Linked list is empty"<<endl;
	}
	
	else{
		Node* temp;
		temp = head;
		
		if(n == 1){
			head = temp->next;
			delete temp;
		}
		
		else{
			for(int i=0; i<n-2; i++){
				temp = temp->next;
			}
			
			Node* temp1;
			temp1 = temp->next;
			
			temp->next = temp1->next;
			temp1->next->prev = temp;
			delete temp1;
		}
	}
}

void Display(){
	Node* temp;
	temp = head;
	
	while(temp->next != NULL){
		cout<<temp->data<<"\t";
		temp = temp->next;
	}
	cout<<temp->data<<endl;
}

void Display_reverse(){
	Node* temp;
	temp = head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	while(temp->prev != NULL){
		cout<<temp->data<<"\t";
		temp = temp->prev;
	}
	cout<<temp->data<<endl;
}

int main(){
	head = NULL;
	int choice, n;
	
	while(2>1){
		cout<<"1.Insert"<<endl;
		cout<<"2.Insert a node at beginning"<<endl;
		cout<<"3.Insert a node at nth position"<<endl;
		cout<<"4.Delete a node at nth position"<<endl;
		cout<<"5.Display"<<endl;
		cout<<"6.Display a linked list in reverse order"<<endl;
		cout<<"7.Exit"<<endl;
		
		cout<<"Enter choice:";
		cin>>choice;
		
		switch(choice){
			
			case 1:
				Insert();
				break;
				
			case 2:
				Insert_node_at_beginning();
				break;
			
			case 3:
				cout<<"Enter Position:";
				cin>>n;
				Insert_node_at_nth_position(n);
				break;
				
			case 4:
				cout<<"Enter Position:";
				cin>>n;
				Delete_node_at_nth_position(n);
				break;
				
			case 5:
				Display();
				break;
				
			case 6:
				Display_reverse();
				break;
				
			case 7:
				exit(0);
				break;
				
			default:
				cout<<"You have entered wrong input"<<endl;
		}
	}
}
