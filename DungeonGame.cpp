#include<iostream>
#include<vector>
using namespace std;

int calculateMinimumHP(vector<vector<int> > &dungeon){
	int m, n, a;
	m = dungeon.size();
	n = dungeon[0].size();

	for(int i=m-1; i>=0; i--){
		for(int j=n-1; j>=0; j--){
			if(i == m - 1 && j == n - 1)
				continue;

			else if(i == m - 1){
				if(dungeon[i][j + 1] < 0){
					a = dungeon[i][j] + dungeon[i][j + 1];
					if(a < 0)
						dungeon[i][j] = a;
				}
			}

			else if(j == n - 1){
				if(dungeon[i + 1][j] < 0){
					a = dungeon[i][j] + dungeon[i + 1][j];
					if(a < 0)
						dungeon[i][j] = a;
				}
			}

			else{
				if(dungeon[i + 1][j] < 0 && dungeon[i][j + 1] < 0){
					a = dungeon[i][j] + max(dungeon[i][j + 1], dungeon[i + 1][j]);
					if(a < 0)
						dungeon[i][j] = a;
				}
			}
		}
	}

	if(dungeon[0][0] >= 0)
		return 1;

	else
		return -dungeon[0][0] + 1;
}

int main(){
	int m, n;
	cin>>m;
	cin>>n;

	vector<vector<int> > dungeon(m, vector<int> (n));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			int num;
			cin>>num;
			dungeon[i][j] = num;
		}
	}

	int result;
	result = calculateMinimumHP(dungeon);

	cout<<result;
}