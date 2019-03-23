#include<iostream>
#include<vector>
using namespace std;

int numDistinct(string s, string t){
	int m, n;
	m = t.size();
	n = s.size();

	vector<vector<int> > dp(m + 1, vector<int> (n + 1));

	for(int i=0; i<=m; i++){
		for(int j=0; j<=n; j++){
			if(i == 0)
				dp[i][j] = 1;

			else if(j == 0)
				dp[i][j] = 0;

			else if(t[i - 1] != s[j - 1])
				dp[i][j] = dp[i][j - 1];

			else
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
		}
	}

	return dp[m][n];
}

int main(){
	string s, t;
	cin>>s;
	cin>>t;

	int result;
	result = numDistinct(s, t);

	cout <<result;
}