#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int> > &matrix){
	int n;
	n = matrix.size();

	for(int i=0; i<n/2; i++){
		for(int j=i; j<n-1-i; j++){
			int temp;
			temp = matrix[i][j];
			matrix[i][j] = matrix[n-1-j][i];
			matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
			matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
			matrix[j][n-1-i] = temp;
		}
	}
}

int main(){
	int n;
	cin>>n;

	vector<vector<int> > arr(n, vector<int> (n));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int num;
			cin>>num;
			arr[i][j] = num;
		}
	}

	rotate(arr);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}
}
