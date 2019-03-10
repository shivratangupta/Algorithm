#include<iostream>
#include<string.h>
#include<vector>
#include<set>
using namespace std;

bool notInRow(vector<vector<char> > &board, int row){
	set<char> s;

	for(int i=0; i<9; i++){
		if(s.find(board[row][i]) != s.end())
			return false;

		if(board[row][i] != '.')
			s.insert(board[row][i]);
	}

	return true;
}

bool notInCol(vector<vector<char> > &board, int col){
	set<char> s;

	for(int i=0; i<9; i++){
		if(s.find(board[i][col]) != s.end())
			return false;

		if(board[i][col] != '.')
			s.insert(board[i][col]);
	}

	return true;
}

bool notInGrid(vector<vector<char> > &board, int startrow, int startcol){
	set<char> s;

	for(int i=0; i<startrow+3; i++){
		for(int j=0; j<startcol+3; j++){
			if(s.find(board[i][j]) != s.end())
				return false;

			if(board[i][j] != '.')
				s.insert(board[i][j]);
		}
	}

	return true;
}

bool isValidSudoku(vector<vector<char> > &board){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(!(notInRow(board, i) && notInCol(board, j) && notInGrid(board, i - i % 3, j - j % 3)))
				return false;
		}
	}

	return true;
}

int main(){

}