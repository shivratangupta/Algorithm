#include<iostream>
#include<vector>
using namespace std;

int minPathSum(vector<vector<int> > &grid){
	int m, n;
	m = grid.size();
	n = grid[0].size();

	vector<vector<int> > dp(m, vector<int> (n));

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(i == 0 && j == 0)
				dp[i][j] = grid[i][j];

			else if(i == 0)
				dp[i][j] = grid[i][j] + dp[i][j - 1];

			else if(j == 0)
				dp[i][j] = grid[i][j] + dp[i - 1][j];

			else
				dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[m - 1][n - 1];
}

int main(){
	int m, n;
	cin>>m;
	cin>>n;

	vector<vector<int> > arr(m, vector<int> (n));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			int num;
			cin>>num;
			arr[i][j] = num;
		}
	}

	int result;
	result = minPathSum(arr);

	cout<<result;
}