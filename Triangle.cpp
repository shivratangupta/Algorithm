#include<iostream>
#include<vector>
using namespace std;

int minimumTotal(vector<vector<int> > &triangle){
	int n;
	n = triangle.size();

	for(int i=n-2; i>=0; i--){
		for(int j=0; j<triangle[i].size(); j++)
			triangle[i][j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1]);
	}

	return triangle[0][0];
}

int main(){
	int n;
	cin>>n;

	vector<vector<int> > arr(n);
	for(int i=0; i<n; i++){
		for(int j=0; j<i+1; j++){
			int num;
			cin>>num;
			arr[i].push_back(num);
		}
	}

	int result;
	result = minimumTotal(arr);

	cout<<result;
}