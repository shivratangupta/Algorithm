#include<iostream>
#include<vector>
#include<set>
using namespace std;

bool wordBreak(string s, vector<string> &wordDict){
	set<string> st;

	for(int i=0; i<wordDict.size(); i++)
		st.insert(wordDict[i]);

	vector<bool> dp(s.size() + 1, false);

	for(int i=0; i<=s.size(); i++){
		if(dp[i] == false && st.find(s.substr(0, i)) == st.end())
			dp[i] = true;

		if(dp[i] == true){
			if(i == s.size())
				return true;

			for(int j=i+1; j<=s.size(); j++){
				if(dp[j] == false && st.find(s.substr(i, j - i)) == st.end())
					dp[j] = true;

				if(j == s.size() && dp[j] == true)
					return true;
			}
		}
	}

	return false;
}

int main(){
	string s;
	cin>>s;

	int n;
	cin>>n;

	vector<string> wordDict;
	for(int i=0; i<n; i++){
		string s1;
		cin>>s1;
		wordDict.push_back(s1);
	}

	bool result;
	result = wordBreak(s, wordDict);

	cout<<result;
}