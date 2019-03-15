#include<iostream>
#include<vector>
using namespace std;

void combination(vector<vector<int> > &result, vector<int> &arr, int curr, int n, int k){
	if(arr.size() == k){
		result.push_back(arr);
		return;
	}

	else if(curr > n)
		return;

	for(int i=curr; i<=n; i++){
		vector<int> temp(arr);
		temp.push_back(i);
		combination(result, temp, i + 1, n, k);
	}
}

vector<vector<int> > combine(int n, int k){
	vector<vector<int> > result;

	for(int i=1; i<=n-k+1; i++){
		vector<int> arr;
		arr.push_back(i);
		combination(result, arr, i + 1, n, k);
	}

	return result;
}

int main(){
	int n, k;
	cin>>n;
	cin>>k;

	vector<vector<int> > result;
	result = combine(n, k);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<k; j++)
			cout<<result[i][j]<<"\t";

		cout<<endl;
	}
}