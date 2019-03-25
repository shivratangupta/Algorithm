#include<iostream>
#include<string.h>
using namespace std;

bool isPalindrome(string s){
	int i, j;
	i = 0;
	j = s.size() - 1;

	while(i < j){
		if(!isalnum(s[i]))
			i++;

		else if(!isalnum(s[j]))
			j--;

		else{
			if(s[i] >= 'A' && s[i] <= 'Z')
				s[i] = tolower(s[i]);

			if(s[j] >= 'A' && s[j] <= 'Z')
				s[j] = tolower(s[j]);

			if(s[i] != s[j])
				return false;

			i++;
			j--;
		}
	}

	return true;
}

int main(){
	string s;
	getline(cin, s);

	bool result;
	result = isPalindrome(s);

	cout<<result;
}