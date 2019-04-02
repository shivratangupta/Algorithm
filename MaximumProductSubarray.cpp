#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int> &nums){
	int max1, min1, result;
	max1 = nums[0];
	min1 = nums[0];
	result = nums[0];

	for(int i=1; i<nums.size(); i++){
		if(nums[i] > 0){
			max1 = max(nums[i], max1 * nums[i]);
			min1 = min(nums[i], min1 * nums[i]);
		}

		else{
			int temp;
			temp = max1;
			max1 = max(nums[i], min1 * nums[i]);
			min1 = min(nums[i], temp * nums[i]);
		}

		result = max(result, max1);
	}

	return result;
}

int main(){
	int n;
	cin>>n;

	vector<int> nums;
	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		nums.push_back(num);
	}

	int result;
	result = maxProduct(nums);

	cout<<result;
}
