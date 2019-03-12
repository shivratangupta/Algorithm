#include<iostream>
#include<string.h>
using namespace std;

int lengthOfLastWord(string s){
	if(s.size() == 0)
		return 0;

	int i;
	i = s.size()-1;

	while(s[i] == ' ')
		i--;


	for(int j=i; j>=0; j--){
		if(s[j] == ' ')
			return i - j;
	}

	return i + 1;
}

int main(){
	string s;
	cin>>s;

	int result;
	result = lengthOfLastWord(s);

	cout<<result;
}