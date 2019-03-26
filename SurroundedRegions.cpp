#include<iostream>
#include<vector>
using namespace std;

void fill(vector<vector<char> > &board, int i, int j, char prev, char next){
	if(i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1)
		return;

	if(board[i][j] != prev)
		return;

	board[i][j] = next;

	fill(board, i + 1, j, prev, next);
	fill(board, i - 1, j, prev, next);
	fill(board, i, j + 1, prev, next);
	fill(board, i, j - 1, prev, next);
}

void solve(vector<vector<char> > &board){
	if(board.size() == 0)
		return;

	int m, n;
	m = board.size();
	n = board[0].size();

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(board[i][j] == 'O')
				board[i][j] = '-';
		}
	}

	for(int i=0; i<n; i++){
		if(board[0][i] == '-')
			fill(board, 0, i, '-', 'O');
	}

	for(int i=0; i<m; i++){
		if(board[i][n - 1] == '-')
			fill(board, i, n - 1, '-', 'O');
	}

	for(int i=0; i<n; i++){
		if(board[m - 1][i] == '-')
			fill(board, m - 1, i, '-', 'O');
	}

	for(int i=0; i<m; i++){
		if(board[i][0] == '-')
			fill(board, i, 0, '-', 'O');
	}

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(board[i][j] == '-')
				board[i][j] = 'X';
		}
	}
}

int main(){
	int m, n;
	cin>>m;
	cin>>n;

	vector<vector<char> > board(m, vector<char> (n));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			char c;
			cin>>c;
			board[i][j] = c;
		}
	}

	solve(board);

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout<<board[i][j]<<"\t";
		}
		cout<<endl;
	}
}
