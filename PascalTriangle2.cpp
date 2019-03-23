#include<iostream>
#include<vector>
using namespace std;

vector<int> getRow(int rowIndex){
	vector<int> result;
	result.push_back(1);

	if(rowIndex == 0)
		return result;

	vector<int> arr;

	for(int i=0; i<rowIndex; i++){
		arr.clear();
		arr.push_back(1);

		for(int j=0; j<result.size()-1; j++)
			arr.push_back(result[j] + result[j + 1]);

		arr.push_back(1);
		result = arr;
	}

	return result;
}

int main(){
	int n;
	cin>>n;

	vector<int> result;
	result = getRow(n);

	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<"\t";
}