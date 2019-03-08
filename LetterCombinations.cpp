#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

void combinations(vector<string> &result, string digits, string s, int i){
	if(i == digits.size()){
		result.push_back(s);
		return;
	}

	if(digits[i] == '2'){
		combinations(result, digits, s + 'a', i + 1);
		combinations(result, digits, s + 'b', i + 1);
		combinations(result, digits, s + 'c', i + 1);
	}

	else if(digits[i] == '3'){
		combinations(result, digits, s + 'd', i + 1);
		combinations(result, digits, s + 'e', i + 1);
		combinations(result, digits, s + 'f', i + 1);
	}

	else if(digits[i] == '4'){
		combinations(result, digits, s + 'g', i + 1);
		combinations(result, digits, s + 'h', i + 1);
		combinations(result, digits, s + 'i', i + 1);
	}

	else if(digits[i] == '5'){
		combinations(result, digits, s + 'j', i + 1);
		combinations(result, digits, s + 'k', i + 1);
		combinations(result, digits, s + 'l', i + 1);
	}

	else if(digits[i] == '6'){
		combinations(result, digits, s + 'm', i + 1);
		combinations(result, digits, s + 'n', i + 1);
		combinations(result, digits, s + 'o', i + 1);
	}

	else if(digits[i] == '7'){
		combinations(result, digits, s + 'p', i + 1);
		combinations(result, digits, s + 'q', i + 1);
		combinations(result, digits, s + 'r', i + 1);
		combinations(result, digits, s + 's', i + 1);
	}

	else if(digits[i] == '8'){
		combinations(result, digits, s + 't', i + 1);
		combinations(result, digits, s + 'u', i + 1);
		combinations(result, digits, s + 'v', i + 1);
	}

	else if(digits[i] == '9'){
		combinations(result, digits, s + 'w', i + 1);
		combinations(result, digits, s + 'x', i + 1);
		combinations(result, digits, s + 'y', i + 1);	
		combinations(result, digits, s + 'z', i + 1);
	}

	return;
}

vector<string> letterCombinations(string digits){
	vector<string> result;
	string s = "";

	combinations(result, digits, s, 0);

	return result;
}

int main(){
	string s;
	cin>>s;

	vector<string> result;
	result = letterCombinations(s);

	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<"\t";
}