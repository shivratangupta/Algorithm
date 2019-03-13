#include<iostream>
#include<string.h>
using namespace std;

bool isNumber(string s){
	int i, n;
	i = 0;
	n = s.size();

	while(i < n && s[i] == ' ')
		i++;

	if(i < n && (s[i] == '+' || s[i] == '-'))
		i++;

	bool num;
	num = false;

	while(i < n && isdigit(s[i])){
		i++;
		num = true;
	}

	if(i < n && s[i] == '.'){
		i++;
		while(i < n && isdigit(s[i])){
			i++;
			num = true;
		}
	}

	if(num && i < n && s[i] == 'e'){
		i++;
		num = false;
		if(i < n && (s[i] == '+' || s[i] == '-'))
			i++;

		while(i < n && isdigit(s[i])){
			i++;
			num = true;
		}
	}

	while(i < n && s[i] == ' ')
		i++;

	return i == n && num;
}

int main(){
	string s;
	cin>>s;

	bool result;
	result = isNumber(s);

	cout<<result;
}