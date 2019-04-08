#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int titleToNumber(string s){
	int result, n;
	result = 0;
	n = s.size() - 1;

	for(int i=0; i<s.size(); i++){
		int a;
		a = (s[i] - 'A') + 1;
		result += (pow(26, n) * a);
		n--;
	}

	return result;
}

int main(){
	string s;
	cin>>s;

	int result;
	result = titleToNumber(s);

	cout<<result;
}
