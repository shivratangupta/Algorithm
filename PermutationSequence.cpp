#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

string getPermutation(int n, int k){
	string s = "";
	for(int i=1; i<=n; i++)
		s += i + '0';

	for(int i=1; i<k; i++)
		next_permutation(s.begin(), s.end());

	return s;
}

int main(){
	int n, k;
	cin>>n;
	cin>>k;

	string result;
	result = getPermutation(n, k);

	cout<<result;
}