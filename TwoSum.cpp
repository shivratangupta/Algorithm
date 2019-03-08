#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
	vector<int> arr;
	for(int i=0; i<nums.size()-1; i++){
		for(int j=i+1; j<nums.size(); j++){
			if(nums[i] + nums[j] == target){
				arr.push_back(i);
				arr.push_back(j);
				break;
			}
		}
	}

	return arr;
}

int main(){
	int n, target;
	cin>>n;
	vector<int> nums;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		nums.push_back(a);
	}

	cin>>target;

	vector<int> result;
	result = twoSum(nums, target);

	for(int i=0; i<result.size(); i++){
		cout<<result[i]<<"\t";
	}
}
