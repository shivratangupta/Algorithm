#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

string simplifyPath(string path){
	string result, s;
	stack<string> st;
	int i, n;
	i = 0;
	n = path.size();

	while(i < n){
		s.clear();

		while(i < n && path[i] == '/')
			i++;

		while(i < n && path[i] != '/'){
			s.push_back(path[i]);
			i++;
		}

		if(s.compare(".") == 0)
			continue;

		else if(s.compare("..") == 0){
			if(!st.empty())
				st.pop();
		}

		else if(s.size() != 0)
			st.push(s);
	}

	stack<string> st1;
	while(!st.empty()){
		st1.push(st.top());
		st.pop();
	}

	result.append("/");

	while(!st1.empty()){
		s = st1.top();

		if(st1.size() == 1)
			result.append(s);

		else
			result.append(s + "/");

		st1.pop();
	}

	return result;
}

int main(){
	string s;
	cin>>s;

	string result;
	result = simplifyPath(s);

	cout<<result;
}