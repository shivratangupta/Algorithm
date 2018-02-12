#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

struct Node{
	char data;
	Node* next;	
};

Node* top;

int main(){
	top = NULL;
	
	string s;
	int flag=0;
	
	cout<<"Enter the expression:";
	cin>>s;
	
	for(int i=0; i<s.size(); i++){
		if(s[i] == '(' | s[i] == '{' | s[i] == '['){
			Node* temp = new Node();
			temp->data = s[i];
			temp->next = NULL;
			
			temp->next = top;
			top = temp;
		}
		
		if(s[i] == ')' | s[i] == '}' | s[i] == ']'){
			
			if(top == NULL){
				flag = 1;
				break;
			}
		
			if(s[i] == ')'){
				if(top->data == '('){
					Node* temp;
					temp = top;
					top = temp->next;
					delete temp;
				}
			}
		
			if(s[i] == '}'){
				if(top->data == '{'){
					Node* temp;
					temp = top;
					top = temp->next;
					delete temp;
				}
			}
		
			if(s[i] == ']'){
				if(top->data == '['){
					Node* temp;
					temp = top;
					top = temp->next;
					delete temp;
				}
			}
		}
	}
	
	if((top == NULL) && (flag == 0)){
		cout<<"Parentheses is balanced";
	}
	
	else{
		cout<<"Parentheses is not balanced";
	}
}
