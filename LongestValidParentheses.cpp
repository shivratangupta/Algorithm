#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

int longestValidParentheses(string s){
	stack<int> st;
	st.push(-1);

	int max;
	max = 0;

	for(int i=0; i<s.size(); i++){
		if(s[i] == '(')
			st.push(i);

		else{
			st.pop();
			if(st.empty())
				st.push(i);

			int a;
			a = i - st.top();

			if(a > max)
				max = a;
		}
	}

	return max;
}

int main(){
	string s;
	cin>>s;

	int result;
	result = longestValidParentheses(s);

	cout<<result;
}