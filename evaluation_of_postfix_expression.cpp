#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* top;

int main(){
	top = NULL;
	
	string s;
	
	cout<<"Enter the postfix expression:";
	cin>>s;
	
	for(int i=0; i<s.size(); i++){
		if(s[i] == '+'){
			Node* temp;
			temp = top;
			top = temp->next;
			
			top->data = top->data + temp->data;
			delete temp;
		}
		
		else if(s[i] == '-'){
			Node* temp;
			temp = top;
			top = temp->next;
			
			top->data = top->data - temp->data;
			delete temp;
		}
		
		else if(s[i] == '*'){
			Node* temp;
			temp = top;
			top = temp->next;
			
			top->data = top->data * temp->data;
			delete temp;
		}
		
		else if(s[i] == '/'){
			Node* temp;
			temp = top;
			top = temp->next;
			
			top->data = top->data / temp->data;
			delete temp;
		}
		
		else{
			Node* temp = new Node();
			temp->data = s[i]-48;
			temp->next = NULL;
			
			temp->next = top;
			top = temp;
		}
	}
	
	cout<<"Answer of this expression is:"<<top->data;
}
