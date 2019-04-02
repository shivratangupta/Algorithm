#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

stack<int> s;
stack<int> t;

void push(int x){
	s.push(x);

	if(t.empty())
		t.push(x);

	else if(x <= t.top())
		t.push(x);
}

void pop(){
	int a;
	a = s.top();
	s.pop();

	if(t.top() == a)
		t.pop();
}

int top(){
	return s.top();
}

int getMin(){
	return t.top();
}

int main(){
	int choice, x;
	
	while(1){
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"3. Top"<<endl;
		cout<<"4. Min"<<endl;
		cout<<"5. Exit"<<endl;

		cout<<"Enter choice:";
		cin>>choice;

		switch(choice){
			case 1:
				cout<<"Enter data:";
				cin>>x;
				push(x);
				break;

			case 2:
				pop();
				break;

			case 3:
				cout<<top()<<endl;
				break;

			case 4:
				cout<<getMin()<<endl;
				break;

			case 5:
				exit(0);
				break;

			default:
				cout<<"You have entered wrong input"<<endl;
		}
	}
}
