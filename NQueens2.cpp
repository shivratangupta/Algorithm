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

void queens(vector<string> &s, int &result, int col, int n){
	if(col == n){
		result++;
		return;
	}

	for(int i=0; i<n; i++){
		if(check(s, i, col, n)){
			s[i][col] = 'Q';
			queens(s, result, col + 1, n);
			s[i][col] = '.';
		}
	}
}

int totalNQueens(int n){
	int result;
	vector<string> s(n, string(n, '.'));
	result = 0;

	queens(s, result, 0, n);

	return result;
}

int main(){
	int n;
	cin>>n;

	int result;
	result = totalNQueens(n);

	cout<<result;
}
