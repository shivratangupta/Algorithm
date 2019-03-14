#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target){
	int m, n, l, r, mid, i, j;
	m = matrix.size();

	if(m == 0)
		return false;

	n = matrix[0].size();

	if(n == 0)
		return false;

	l = 0;
	r = m - 1;
	mid = (l + r) / 2;

	while(l <= r){
		if(mid == 0 && matrix[mid][n - 1] >= target){
			i = mid;
			break;
		}

		else if(matrix[mid][n - 1] >= target && matrix[mid - 1][n - 1] < target){
			i = mid;
			break;
		}

		else if(matrix[mid][n - 1] < target)
			l = mid + 1;

		else
			r = mid - 1;

		mid = (l + r) / 2;	
	}

	l = 0;
	r = m - 1;

	mid = (l + r) / 2;

	while(l <= r){
		if(matrix[i][mid] == target)
			return true;

		else if(matrix[i][mid] < target)
			l = mid + 1;

		else
			r = mid - 1;

		mid = (l + r) / 2;
	}

	return false;
}

int main(){
	int m, n, target;
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

	cin>>target;

	bool result;
	result = searchMatrix(arr, target);

	cout<<result;
}