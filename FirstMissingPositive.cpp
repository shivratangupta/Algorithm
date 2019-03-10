#include<iostream>
#include<vector>
using namespace std;

int firstMissingPositive(vector<int> &nums){
	if(nums.size() == 0)
		return 1;

	for(int i=0; i<nums.size(); i++){
		if(nums[i] <= nums.size() && nums[i] > 0 && nums[nums[i] - 1] != nums[i]){
			int temp;
			temp = nums[nums[i] - 1];
			nums[nums[i] - 1] = nums[i];
			nums[i] = temp;
			i--;
		}
	}

	for(int i=0; i<nums.size(); i++){
		if(nums[i] != i + 1)
			return i + 1;
	}

	return nums.size() + 1;
}

int main(){
	int n;
	cin>>n;

	vector<int> arr;
	for(int i=0; i<n; i++){
		int nums;
		cin>>nums;
		arr.push_back(nums);
	}
	
	int result;
	result = firstMissingPositive(arr);

	cout<<result;
}
