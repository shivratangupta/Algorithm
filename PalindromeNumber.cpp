#include<iostream>
#include<string.h>
using namespace std;

bool isPalindrome(int x){
	if(x < 0)
		return false;

	string s;
	s = to_string(x);
	int i, j;
	i = 0;
	j = s.size()-1;

	while(i < j){
		if(s[i] != s[j])
			return false;

		i++;
		j--;
	}

	return true;
}

int main(){
	int n;
	cin>>n;

	bool result;

	result = isPalindrome(n);

	cout<<result;
}
