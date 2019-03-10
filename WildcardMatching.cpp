#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

bool isMatch(string s, string p){
	if(p.size() == 0){
		if(s.size() == 0)
			return true;

		else
			return false;
	}

	vector<vector<bool> > dp(s.size() + 1, vector<bool> (p.size() + 1, false));

	dp[0][0] = true;

	for(int j=1; j<=p.size(); j++){
		if(p[j-1] == '*')
			dp[0][j] = dp[0][j-1];
	}

	for(int i=1; i<=s.size(); i++){
		for(int j=1; j<=p.size(); j++){
			if(p[j-1] == '*')
				dp[i][j] = dp[i][j-1] || dp[i-1][j];

			else if(p[j-1] == '?' || s[i-1] == p[j-1])
				dp[i][j] = dp[i-1][j-1];

			else
				dp[i][j] = false;
		}
	}

	return dp[s.size()][p.size()];
}

int main(){
	string s, p;
	cin>>s;
	cin>>p;

	bool result;
	result = isMatch(s, p);

	cout<<result;
}
