#include<iostream>
#include<stdlib.h>
using namespace std;

int arr[10];
int front = -1, rear = -1;
int N = 10;

void Push(){
	if((rear+1)%N == front){
		cout<<"Queue is Full"<<endl;
		return;
	}
	
	else if(front == -1 && rear == -1){
		front = front + 1;
		rear =  rear + 1;
	}
	
	else{
		rear = (rear + 1) % N;
	}
	
	cout<<"Enter data:";
	cin>>arr[rear];
	
}

void Pop(){
	if(front == -1 && rear == -1){
		cout<<"Queue is empty"<<endl;
		return;
	}
	
	else if(front == rear){
		front = -1;
		rear = -1;
	}
	
	else{
		front = (front + 1) % N;
	}
}

void Front(){
	if(front == -1 && rear == -1){
		cout<<"Queue is empty"<<endl;
		return;
	}
	
	else{
		cout<<arr[front]<<endl;
	}
}

void Isempty(){
	if(front == -1 && rear == -1){
		cout<<"Queue is empty"<<endl;
	}
	
	else{
		cout<<"Queue is not empty"<<endl;
	}
}

int main(){
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
				break;
		}
	}
}
