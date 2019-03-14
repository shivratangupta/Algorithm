#include<iostream>
#include<vector>
using namespace std;

int minDistance(string word1, string word2){
	int m, n;
	m = word1.size();
	n = word2.size();

	vector<vector<int> > dp(m + 1, vector<int> (n + 1));

	for(int i=0; i<m+1; i++){
		for(int j=0; j<n+1; j++){
			if(i == 0)
				dp[i][j] = j;

			else if(j == 0)
				dp[i][j] = i;

			else if(word1[i-1] == word2[j-1])
				dp[i][j] = dp[i-1][j-1];

			else{
				int a;
				a = min(dp[i][j-1], dp[i-1][j]);
				dp[i][j] = 1 + min(a, dp[i-1][j-1]);
			}
		}
	}

	return dp[m][n];
}

int main(){
	string s, s1;
	cin>>s;
	cin>>s1;

	int result;
	result = minDistance(s, s1);

	cout<<result;
}