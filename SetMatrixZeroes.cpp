#include<iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int> > &matrix){
	int m, n;
	bool row, col;
	m = matrix.size();
	n = matrix[0].size();
	row = false;
	col = false;

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(i == 0 && matrix[i][j] == 0)
				row = true;

			if(j == 0 && matrix[i][j] == 0)
				col = true;

			if(matrix[i][j] == 0){
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
			if(matrix[0][j] == 0 || matrix[i][0] == 0)
				matrix[i][j] = 0;
		}
	}

	if(row == true){
		for(int i=0; i<n; i++)
			matrix[0][i] = 0;
	}

	if(col == true){
		for(int i=0; i<m; i++)
			matrix[i][0] = 0;
	}
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

	setZeroes(arr);
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}
}