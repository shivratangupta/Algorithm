#include<iostream>
#include<string.h>
using namespace std;

string countAndSay(int n){
	string s;
	string s1 = "";

	if(n < 1)
		return s1;

	s1 += '1';
	s = s1;
	s1 = "";

	int count;
	count = 1;

	for(int i=2; i<=n; i++){
		for(int j=0; j<s.size()-1; j++){
			if(s[j] == s[j+1])
				count++;

			else{
				s1 += count + '0';
				s1 += s[j];
				count = 1;
			}
		}

		s1 += count + '0';
		s1 += s[s.size()-1];
		s = s1;
		s1 = "";
		count = 1;
	}

	return s;
}

int main(){
	int n;
	cin>>n;

	string result;
	result = countAndSay(n);

	cout<<result;
}