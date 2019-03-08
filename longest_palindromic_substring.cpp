#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

string LongestPalindromicSubstring(string s){
	int n, length, start;
	n = s.size();

	vector<vector<bool> > dp(n, vector<bool> (n, false));

	length = 1;
	start = 0;

	for(int i=0; i<n; i++)
		dp[i][i] = true;

	for(int i=0; i<n-1; i++){
		if(s[i] == s[i+1]){
			dp[i][i+1] = true;
			start = i;
			length = 2;
		}
	}

	for(int k=3; k<=n; k++){
		for(int i=0; i<n-k+1; i++){
			int j;
			j = i + k- 1;
			if(dp[i+1][j-1] == true && s[i] == s[j]){
				dp[i+1][j-1] = true;
				start = i;
				length = k;
			}
		}
	}

	string result;

	result = s.substr(start, length);

	return result;
}

int main(){
	string s;
	cin>>s;

	string result;
	
	result = LongestPalindromicSubstring(s);

	cout<<result;
}
