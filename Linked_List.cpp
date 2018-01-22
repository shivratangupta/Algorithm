#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head;

void Insert(){
	
	if(head == NULL){
		Node* temp = new Node();
		cout<<"Enter data:";
		cin>>temp->data;
		temp->next = NULL;
		head = temp;	
	}
	
	else{
		Node* temp = new Node();
		cout<<"Enter data:";
		cin>>temp->data;
		temp->next = NULL;
		
		Node* temp1;
		temp1 = head;
		
		while(temp1->next != NULL){
			temp1 = temp1->next;
		}
		
		temp1->next = temp;
	}
}

void Insert_node_at_beginning(){
	if(head == NULL){
		Node* temp = new Node();
		cout<<"Enter data:";
		cin>>temp->data;
		temp->next = NULL;
		head = temp;
	}
	
	else{
		Node* temp = new Node();
		cout<<"Enter data:";
		cin>>temp->data;
		temp->next = head;
		head = temp;
	}
}

void Insert_node_at_nth_position(int n){
	Node* temp = new Node();
	cout<<"Enter data:";
	cin>>temp->data;
	temp->next = NULL;
	
	if(n == 1){
		
		temp->next = head;
		head = temp;
	}
	
	else{
		
		Node* temp1;
		temp1 =head;
		
		for(int i=0; i<n-2; i++){
			temp1 = temp1->next;
		}
		
		temp->next = temp1->next;
		temp1->next = temp;
	}
}

void Delete(int n){
	if(head == NULL){
		cout<<"Linked List is empty"<<endl;
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
			delete temp1;	
		}
	}
}

void Reverse(){
	
	Node *current, *prev, *next;
	current = head;
	prev = NULL;
	
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	head = prev;
}

void Display(){
	
	if(head == NULL){
		cout<<"List is empty"<<endl;
	}
	
	else{
		Node* temp;
		temp = head;
		
		while(temp->next != NULL){
			cout<<temp->data<<"\t";
			temp = temp->next;
		}
		cout<<temp->data<<endl;
	}
}

void Display_reverse(Node* p){
	
	if(p == NULL){
		return;
	}
	
	Display_reverse(p->next);
	cout<<p->data<<"\t";
}

int main(){
	head = NULL;
	
	int choice, n;
	
	while(2>1){
		
		cout<<"1.Insert"<<endl;
		cout<<"2.Insert a node at beginning"<<endl;
		cout<<"3.Insert a node at nth position"<<endl;
		cout<<"4.Delete a node at nth position"<<endl;
		cout<<"5.Reverse a linkedlist"<<endl;
		cout<<"6.Display"<<endl;
		cout<<"7.Display a linked list in reverse order"<<endl;
		cout<<"8.Exit"<<endl;
		
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
				cout<<"Enter position:";
				cin>>n;
				Insert_node_at_nth_position(n);
				break;
				
			case 4:
				cout<<"Enter position:";
				cin>>n;
				Delete(n);
				break;
				
			case 5:
				Reverse();
				break;
				
			case 6:
				Display();
				break;
			
			case 7:
				Display_reverse(head);
				cout<<endl;
				break;
				
			case 8:
				exit(0);
				break;
			
			default:
				cout<<"You have entered wrong input"<<endl;
				break;
		}
	}
}
