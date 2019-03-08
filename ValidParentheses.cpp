#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

bool isValid(string s){
	if(s.size() == 0)
		return true;

	stack<char> st;

	for(int i=0; i<s.size(); i++){
		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
			st.push(s[i]);

		else if(s[i] == ')' && !st.empty() && st.top() == '(')
			st.pop();

		else if(s[i] == '}' && !st.empty() && st.top() == '{')
			st.pop();

		else if(s[i] == ']' && !st.empty() && st.top() == '[')
			st.pop();

		else
			return false;
	}

	if(st.empty())
		return true;

	else
		return false;
}

int main(){
	string s;
	cin>>s;

	bool result;
	result = isValid(s);

	cout<<result;
}
