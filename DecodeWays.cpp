#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int numDecodings(string s){
	if(s[0] == '0')
		return 0;
	int n;
	n = s.size();

	vector<int> dp(n + 1);
	dp[0] = 1;
	dp[1] = 1;

	for(int i=2; i<n+1; i++){
		if(s[i-1] > '0')
			dp[i] = dp[i - 1];

		if(s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] < '7')
			dp[i] += dp[i - 2];
	}

	return dp[n];
}

int main(){
	string s;
	cin>>s;

	int result;
	result = numDecodings(s);

	cout<<result;
}