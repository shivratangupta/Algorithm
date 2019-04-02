#include<iostream>
#include<string.h>
using namespace std;

string reverseWords(string s){
	int n, i;
	n = s.size();
	i = 0;

	string result, s1;

	while(i < n && s[i] == ' ')
		i++;

	int j;
	while(i < n){
		j = i;
		while(i < n && s[i] != ' ')
			i++;

		s1 = s.substr(j, i - j);
		s1 = s1 + " " + result;
		result = s1;

		while(i < n && s[i] == ' ')
			i++;
	}

	if(result.size() != 0){
		int a = result.size();
		result = result.substr(0, a - 1);
	}

	return result;
}

int main(){
	string s;
	getline(cin, s);

	string result;
	result = reverseWords(s);

	cout<<result;
}
