#include<iostream>
#include<string.h>
using namespace std;

string convertToTitle(int n){
	string result;

	while(n != 0){
		int a;
		a = (n - 1) % 26;
		char c;
		c = a + 'A';

		result = c + result;
		n = (n - 1) / 26;
	}

	return result;
}

int main(){
	int n;
	cin>>n;

	string result;
	result = convertToTitle(n);

	cout<<result;
}