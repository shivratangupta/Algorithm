#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &nums, int i, int j){
	int temp;
	temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void permutation(vector<int> &nums, vector<vector<int> > &result, int l, int r){
	if(l == r){
		result.push_back(nums);
		return;
	}

	for(int i=l; i<=r; i++){
		swap(nums, l, i);
		permutation(nums, result, l + 1, r);
		swap(nums, l, i);
	}
}

vector<vector<int> > permute(vector<int> &nums){
	vector<vector<int> > result;

	if(nums.size() == 0)
		return result;

	permutation(nums, result, 0, nums.size()-1);

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
	result = permute(arr);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<n; j++){
			cout<<result[i][j]<<"\t";		
		}
		cout<<endl;
	}
}