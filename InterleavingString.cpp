#include<iostream>
#include<vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3){
	int m, n;
	m = s1.size();
	n = s2.size();

	if(m + n != s3.size())
		return false;

	vector<vector<bool> > dp(m + 1, vector<bool> (n + 1, false));

	for(int i=0; i<=m; i++){
		for(int j=0; j<=n; j++){
			if(i == 0 && j == 0)
				dp[i][j] = true;

			else if(i == 0 && s2[j - 1] == s3[j - 1])
				dp[i][j] = dp[i][j - 1];

			else if(j == 0 && s1[i - 1] == s3[i - 1])
				dp[i][j] = dp[i - 1][j];

			else if(s1[i - 1] == s3[i + j - 1] && s2[j - 1] != s3[i + j - 1])
				dp[i][j] = dp[i - 1][j];

			else if(s1[i - 1] != s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
				dp[i][j] = dp[i][j - 1];

			else if(s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
		}
	}

	return dp[m][n];
}

int main(){
	string s1, s2, s3;
	cin>>s1;
	cin>>s2;
	cin>>s3;

	bool result;
	result = isInterleave(s1, s2, s3);

	cout<<result;
}