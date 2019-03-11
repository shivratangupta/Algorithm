#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix){
	vector<int> result;

	if(matrix.empty())
		return result;

	int m, n, i, j;
	m = matrix.size();
	n = matrix[0].size();
	i = 0;
	j = 0;

	while(i < m && j < n){
		for(int k=j; k<n; k++)
			result.push_back(matrix[i][k]);

		i++;

		for(int k=i; k<m; k++)
			result.push_back(matrix[k][n-1]);

		n--;

		if(i < m){
			for(int k=n-1; k>=j; k--)
				result.push_back(matrix[m-1][k]);

			m--;
		}

		if(j < n){
			for(int k=m-1; k>=i; k--)
				result.push_back(matrix[k][j]);

			j++;
		}
	}

	return result;
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

	vector<int> result;
	result = spiralOrder(arr);

	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<"\t";
}
