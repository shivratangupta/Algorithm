#include<iostream>
#include<stdlib.h>
#include<list>
#include<map>
using namespace std;

int capacity;
list<pair<int, int> > l;
map<int, list<pair<int, int> > :: iterator > m;

int get(int key){
	if(m.find(key) == m.end())
		return -1;

	list<pair<int, int> > :: iterator it;
	it = m[key];

	pair<int, int> p = *it;
	l.erase(m[key]);

	l.push_front(p);
	m[key] = l.begin();

	return p.second;
}

void put(int key, int value){
	if(m.find(key) == m.end()){
		if(l.size() == capacity){
			pair<int, int> p = l.back();
			l.pop_back();
			m.erase(p.first);
		}
	}

	else
		l.erase(m[key]);

	l.push_front(make_pair(key, value));
	m[key] = l.begin();
}

int main(){
	int choice, key, value, cap;

	cout<<"Enter the Capacity:";
	cin>>cap;

	capacity = cap;

	while(1){
		cout<<"1. Get"<<endl;
		cout<<"2. Put"<<endl;
		cout<<"3. Exit"<<endl;

		cout<<"Enter choice:";
		cin>>choice;

		switch(choice){
			case 1:
				cout<<"Enter Key:";
				cin>>key;
				cout<<get(key)<<endl;
				break;

			case 2:
				cout<<"Enter Key:";
				cin>>key;
				cout<<"Enter Value:";
				cin>>value;
				put(key, value);
				break;

			case 3:
				exit(0);
				break;

			default:
				cout<<"You have entered wrong input please enter again"<<endl;
		}
	}
}
