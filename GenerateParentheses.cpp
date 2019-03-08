#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

void parenthesisCombination(vector<string> &result, string s, int m, int n){
	if(m == 0 && n == 0){
		result.push_back(s);
		return;
	}

	if(m > 0)
		parenthesisCombination(result, s + '(', m - 1, n);

	if(m < n)
		parenthesisCombination(result, s + ')', m , n - 1);
}

vector<string> generateParenthesis(int n){
	vector<string> result;
	string s = "";

	parenthesisCombination(result, s, n, n);

	return result;
}

int main(){
	int n;
	cin>>n;

	vector<string> result;
	result = generateParenthesis(n);

	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<endl;
}