#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int> &nums){
	int count, x;
	count = 1;
	x = nums[0];

	for(int i=1; i<nums.size(); i++){
		if(nums[i] == x)
			count++;

		else
			count--;

		if(count == 0){
			count = 1;
			x = nums[i];
		}
	}

	return  x;
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
	result = majorityElement(nums);

	cout<<result;
}