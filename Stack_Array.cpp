#include<iostream>
#include<stdlib.h>
#include<conio.h>
#define max_size 10
using namespace std;

int arr[max_size];
int top = -1;

void Push(int x){
	if(top == max_size - 1){
		cout<<"Error: Stach Overflow"<<endl;
	}
	
	else{
		top++;
		arr[top] = x;
	}
}

void Pop(){
	if(top == -1){
		cout<<"Error: Stack Underflow"<<endl;
	}
	
	else{
		top--;
	}
}

void Top(){
	cout<<arr[top]<<endl;
}

void Isempty(){
	if(top == -1){
		cout<<"True"<<endl;
	}
	
	else{
		cout<<"False"<<endl;
	}
}

int main(){
	int choice, x;
	
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
				cout<<"Enter data:";
				cin>>x;
				Push(x);
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
