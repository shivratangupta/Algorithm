#include<iostream>
#include<vector>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;

vector<vector<string> > groupAnagrams(vector<string> &strs){
	vector<vector<string> > result;
	map<string, vector<string> > m;

	for(int i=0; i<strs.size(); i++){
		string s;
		s = strs[i];
		sort(s.begin(), s.end());
		m[s].push_back(strs[i]);
	}
	
	map<string, vector<string> > :: iterator it;
	for(it = m.begin(); it != m.end(); it++){
		vector<string> arr;
		arr = it->second;
		sort(arr.begin(), arr.end());
		result.push_back(arr);
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

	vector<vector<string> > result;
	result = groupAnagrams(arr);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++){
			cout<<result[i][j]<<"\t";
		}
		cout<<endl;
	}
}
