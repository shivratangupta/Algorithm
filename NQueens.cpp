#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

bool check(vector<string> &s, int row, int col, int n){
	for(int i=0; i<col; i++){
		if(s[row][i] == 'Q')
			return false;
	}

	for(int i=row, j=col; i>=0 && j>=0; i--, j--){
		if(s[i][j] == 'Q')
			return false;
	}

	for(int i=row, j=col; i<n && j>=0; i++, j--){
		if(s[i][j] == 'Q')
			return false;
	}

	return true;
}

void queens(vector<vector<string> > &result, vector<string> &s, int col, int n){
	if(col == n){
		result.push_back(s);
		return;
	}

	for(int i=0; i<n; i++){
		if(check(s, i, col, n)){
			s[i][col] = 'Q';
			queens(result, s, col + 1, n);
			s[i][col] = '.';
		}
	}
}

vector<vector<string> > solveNQueens(int n){
	vector<vector<string> > result;
	vector<string> s(n, string(n, '.'));

	queens(result, s, 0, n);

	return result;
}

int main(){
	int n;
	cin>>n;

	vector<vector<string> > result;
	result = solveNQueens(n);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<n; j++){
			cout<<result[i][j]<<endl;
		}
		cout<<endl;
	}
}