#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs){
	string result = "";
	result = strs[0];

	for(int i=1; i<strs.size(); i++){
		if(strs[i].size() < result.size())
			result = strs[i];
	}

	for(int i=0; i<strs.size(); i++){
		for(int j=0; j<result.size(); j++){
			if(strs[i][j] != result[j]){
				result.erase(j, result.size() - j);
				break;
			}
		}
	}

	return result;
}

int main(){
	int n;
	cin>>n;

	vector<string> arr;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		arr.push_back(s);
	}

	string result;
	result = longestCommonPrefix(arr);

	cout<<result;
}