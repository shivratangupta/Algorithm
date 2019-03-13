#include<iostream>
#include<vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid){
	int m, n;
	m = obstacleGrid.size();
	n = obstacleGrid[0].size();

	vector<vector<int> > dp(m, vector<int> (n));

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(i == 0 && j == 0 && obstacleGrid[i][j] == 0)
				dp[i][j] = 1;

			else if(i == 0 && obstacleGrid[i][j] == 0 && dp[i][j-1] == 1)
				dp[i][j] = 1;

			else if(j == 0 && obstacleGrid[i][j] == 0 && dp[i-1][j] == 1)
				dp[i][j] = 1;

			else{
				if(obstacleGrid[i][j] == 0)
					dp[i][j] = dp[i-1][j] + dp[i][j-1];
			} 
		}
	}

	return dp[m-1][n-1];
}

int main(){
	int m, n;
	cin>>m;
	cin>>n;

	vector<vector<int> > arr(m, vector<int> (n, 0));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			int num;
			cin>>num;
			arr[i][j] = num;
		}
	}

	int result = uniquePathsWithObstacles(arr);

	cout<<result;
}
