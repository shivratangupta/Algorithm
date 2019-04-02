#include<iostream>
#include<vector>
#include<stack>
#include<string.h>
using namespace std;

int evaluateRPN(vector<string> &tokens){
	stack<long long int> s;

	for(int i=0; i<tokens.size(); i++){
		if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
			long long int a, b;
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();

			if(tokens[i] == "+")
				s.push(b + a);

			else if(tokens[i] == "-")
				s.push(b - a);

			else if(tokens[i] == "*")
				s.push(b * a);

			else
				s.push(b / a);
		}

		else{
			int num, j;
			string s1;
			bool neg;
			s1 = tokens[i];
			j = 0;
			num = 0;
			neg = false;

			if(s1[j] == '-')
				neg = true;

			while(j < s1.size()){
				num = num * 10 + (s1[j] - '0');
				j++;
			}

			if(neg)
				num = -num;

			s.push(num);
		}
	}

	return s.top();
}

int main(){
	int n;
	cin>>n;

	vector<string> tokens;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		tokens.push_back(s);
	}

	int result;
	result = evaluateRPN(tokens);

	cout<<result;
}
