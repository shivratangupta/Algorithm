#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

string convert(string s, int numRows){
	vector<string> arr(numRows);

	int row;
	bool down;
	down = false;
	row = 0;

	for(int i=0; i<s.size(); i++){
		arr[row].push_back(s[i]);

		if(row == 0)
			down = true;

		if(row == numRows - 1)
			down = false;

		if(down)
			row++;

		else
			row--;
	}

	string result="";

	for(int i=0; i<numRows; i++){
		result += arr[i];
	}

	return result;	
}

int main(){
	string s;
	cin>>s;

	int n;
	cin>>n;

	string result;

	result = convert(s, n);

	cout<<result;
}