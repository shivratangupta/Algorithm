#include<iostream>
#include<string.h>
using namespace std;

int romanToVal(char c){
	if(c == 'I')
		return 1;

	else if(c == 'V')
		return 5;

	else if(c == 'X')
		return 10;

	else if(c == 'L')
		return 50;

	else if(c == 'C')
		return 100;

	else if(c == 'D')
		return 500;

	else 
		return 1000;
}

int romanToInt(string s){
	int a, b, result;
	result = 0;

	for(int i=s.size()-1; i>=0; i--){
		a = romanToVal(s[i]);

		if(i != 0)
			b = romanToVal(s[i-1]);

		result += a;
		if(b < a){
			result -= b;
			i--;
		}

		a = 0;
		b = 0;
	}

	return result;
}

int main(){
	string s;
	cin>>s;

	int result;
	result = romanToInt(s);

	cout<<result;
}