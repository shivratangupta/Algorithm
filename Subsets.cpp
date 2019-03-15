#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > subsets(vector<int> &nums){
	vector<vector<int> > result(1, vector<int> (0));

	for(int i=0; i<nums.size(); i++){
		int n;
		n = result.size();

		for(int j=0; j<n; j++){
			vector<int> arr(result[j].begin(), result[j].end());
			arr.push_back(nums[i]);
			result.push_back(arr);
		}
	}

	return result;
}

int main(){
	int n;
	cin>>n;

	vector<int> arr;
	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		arr.push_back(num);
	}

	vector<vector<int> > result;
	result = subsets(arr);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<"\t";

		cout<<endl;
	}
}
