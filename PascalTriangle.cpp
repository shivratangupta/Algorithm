#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > generate(int numRows){
	vector<vector<int> > result;

	if(numRows == 0)
		return result;

	vector<int> arr;
	arr.push_back(1);
	result.push_back(arr);

	for(int i=1; i<numRows; i++){
		arr.clear();
		arr.push_back(1);

		for(int j=0; j<result[i-1].size()-1; j++){
			arr.push_back(result[i-1][j] + result[i - 1][j + 1]);
		}
		arr.push_back(1);

		result.push_back(arr);
	}

	return result;
}

int main(){
	int n;
	cin>>n;

	vector<vector<int> > result;
	result = generate(n);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++){
			cout<<result[i][j]<<"\t";
		}

		cout<<endl;
	}
}