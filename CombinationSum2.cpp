#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void combination(vector<int> &candidates, set<vector<int> > &result, vector<int> &arr, int target, int i){
	if(target < 0)
		return;

	if(target == 0){
		result.insert(arr);
		return;
	}

	while(i < candidates.size() && target - candidates[i] >= 0){
		arr.push_back(candidates[i]);

		combination(candidates, result, arr, target - candidates[i], i + 1);
		i++;

		arr.pop_back();
	}
}

vector<vector<int> > combinationSum2(vector<int> &candidates, int target){
	sort(candidates.begin(), candidates.end());

	set<vector<int> > result;
	vector<int> arr;

	combination(candidates, result, arr, target, 0);

	vector<vector<int> > result1;

	set<vector<int> > :: iterator it;

	for(it = result.begin(); it != result.end(); it++)
		result1.push_back(*it);

	return result1;
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
	result = combinationSum2(arr, target);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++){
			cout<<result[i][j]<<"\t";
		}
		cout<<endl;
	}
}
