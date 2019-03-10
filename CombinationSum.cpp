#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void combination(vector<int> &candidates, vector<vector<int> > &result, vector<int> &arr, int target, int i){
	if(target < 0)
		return;

	if(target == 0){
		result.push_back(arr);
		return;
	}

	while(i < candidates.size() && target - candidates[i] >= 0){
		arr.push_back(candidates[i]);

		combination(candidates, result, arr, target - candidates[i], i);
		i++;

		arr.pop_back();
	}
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target){
	sort(candidates.begin(), candidates.end());

	vector<vector<int> > result;
	vector<int> arr;

	combination(candidates, result, arr, target, 0);

	return result;
}

int main(){
	int n, target;
	cin>>n;

	vector<int> arr;
	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		arr.push_back(num);
	}

	cin>>target;

	vector<vector<int> > result;
	result = combinationSum(arr, target);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++){
			cout<<result[i][j]<<"\t";
		}
		cout<<endl;
	}
}
