#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

void fill(vector<vector<bool> > &rows, vector<vector<bool> > &cols, vector<vector<bool> > &grid, int row, int col, char c, bool b){
	rows[row][c - '1'] = b;
	cols[c - '1'][col] = b;
	grid[3 * (row / 3) + (col / 3)][c - '1'] = b;
}

bool dfs(vector<vector<char> > &board, vector<vector<bool> > &rows, vector<vector<bool> > cols, vector<vector<bool> > grid, int index){
	if(index >= 81)
		return true;

	bool solved;
	int row, col;
	solved = false;
	row = index / 9;
	col = index % 9;

	if(board[row][col] == '.'){
		for(int i=0; i<9; i++){
			if(!rows[row][i] && !cols[i][col] && !grid[3 * (row / 3) + (col / 3)][i]){
				char c;
				c = i + '1';
				board[row][col] = c;

				fill(rows, cols, grid, row, col, c, true);

				solved = dfs(board, rows, cols, grid, index + 1);

				if(!solved){
					board[row][col] = '.';
					fill(rows, cols, grid, row, col, c, false);
				}
			}
		}
	}

	else
		solved = dfs(board, rows, cols, grid, index + 1);

	return solved;
}

void solveSudoku(vector<vector<char> > &board){
	vector<vector<bool> > rows(9, vector<bool> (9, false));
	vector<vector<bool> > cols(9, vector<bool> (9, false));
	vector<vector<bool> > grid(9, vector<bool> (9, false));

	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			char c = board[i][j];
			if(board[i][j] != '.')
				fill(rows, cols, grid, i, j, c, true);
		}
	}

	dfs(board, rows, cols, grid, 0);
}

int main(){

}