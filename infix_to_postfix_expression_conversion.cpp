#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stack>
using namespace std;

bool isoperator(char c){
	if(c == '+' | c == '-' | c == '*' | c == '/' | c == '^'){
		return true;
	}
	
	else{
		return false;
	}
}

bool isoperand(char c){
	if((c >= '0' && c <= '9') | (c >= 'a' && c <= 'z') | (c >= 'A' && c <= 'Z')){
		return true;
	}
	
	else{
		return false;
	}
}

int operatorweight(char op){
	int weight = -1;
	
	if(op == '+' | op == '-'){
		weight = 1;
	}
	
	if(op == '*' | op == '/'){
		weight = 2;
	}
	
	if(op == '^'){
		weight = 3;
	}
	
	return weight;
}

bool rightassociative(char op){
	if(op == '^'){
		return true;
	}
	
	else{
		return false;
	}
}

bool precidence(char op1, char op2){
	int weight1 = operatorweight(op1);
	int weight2 = operatorweight(op2);
	
	if(weight1 == weight2){
		if(rightassociative(op1)){
			return false;
		}
		else{
			return true;
		}
	}
	
	else{
		return weight1 > weight2 ? true : false;
	}
}

int main(){
	string in;
	string post="";
	
	cout<<"Enter the infix expression:";
	cin>>in;
	
	stack<char> s;
	
	for(int i=0; i<in.size(); i++){
		if(isoperator(in[i])){
			while(!s.empty() && s.top() != '(' && precidence(s.top(), in[i])){
				post = post + s.top();
				s.pop();
			}
			
			s.push(in[i]);
		}
		
		if(isoperand(in[i])){
			post = post + in[i];
		}
		
		if(in[i] == '('){
			s.push(in[i]);
		}
		
		if(in[i] == ')'){
			while(s.top() != '('){
				post = post + s.top();
				s.pop();
			}
			
			s.pop();
		}
	}
	
	while(!s.empty()){
		post = post + s.top();
		s.pop();
	}
	
	cout<<"Postfix expression is:"<<post;
}
