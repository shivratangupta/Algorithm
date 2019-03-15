#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

bool check(vector<vector<char> > &board, string word, int i, int j, int index){
    if(index == word.size())
        return true;
        
    if(i < 0 || j < 0 || i > board.size()-1 || j > board[0].size()-1)
        return false;
        
    if(board[i][j] != word[index])
        return false;
        
    board[i][j] = '*';
        
    bool temp;
        
    temp = check(board, word, i + 1, j, index + 1) ||
           check(board, word, i - 1, j, index + 1) ||
           check(board, word, i, j + 1, index + 1) ||
           check(board, word, i, j - 1, index + 1);
        
    board[i][j] = word[index];
        
    return temp;
}
    
bool exist(vector<vector<char> >& board, string word) {
        
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(check(board, word, i, j, 0))
                return true;
        }
    }
        
    return false;
}

int main(){
	int m, n;
	cin>>m;
	cin>>n;

	vector<vector<char> > arr(m, vector<char> (n));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			char c;
			cin>>c;
			arr[i][j] = c;
		}
	}

	string s;
	cin>>s;

	bool result;
	result = exist(arr, s);

	cout<<result;
}
