#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

bool isPalindrome(string s){
	int i, j;
	i = 0;
	j = s.size() - 1;

	while(i < j){
		if(s[i] != s[j])
			return false;

		i++;
		j--;
	}

	return true;
}

void possiblePartitions(vector<vector<string> > &result, vector<string> &arr, string s, int start, int end){
	if(start > end){
		result.push_back(arr);
		return;
	}

	for(int i=start; i<=end; i++){
		if(isPalindrome(s.substr(start, i - start + 1))){
			arr.push_back(s.substr(start, i - start + 1));
			possiblePartitions(result, arr, s, i + 1, end);
			arr.pop_back();
		}
	}
}

vector<vector<string> > partition(string s){
	vector<vector<string> > result;
	vector<string> arr;

	possiblePartitions(result, arr, s, 0, s.size() - 1);

	return result;
}

int main(){
	string s;
	cin>>s;

	vector<vector<string> > result;
	result = partition(s);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++){
			cout<<result[i][j]<<"\t";
		}
		cout<<endl;
	}
}
