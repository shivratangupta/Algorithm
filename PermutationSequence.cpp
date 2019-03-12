#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

string getPermutation(int n, int k){
	string s = "";
	for(int i=1; i<=n; i++)
		s += i + '0';

	vector<int> factorial(n + 1, 1);
	int fact;
	fact = 1;
	for(int i=1; i<=n; i++){
		fact *= i;
		factorial[i] = fact;
	}

	k--;

	string result = "";
	for(int i=1; i<=n; i++){
		int index;
		index = k / factorial[n - i];
		result += s[index];
		s.erase(s.begin() + index);
		k -= index * factorial[n - i];
	}

	return result;
}

int main(){
	int n, k;
	cin>>n;
	cin>>k;

	string result;
	result = getPermutation(n, k);

	cout<<result;
}
