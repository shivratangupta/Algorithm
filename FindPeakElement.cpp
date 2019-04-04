#include<iostream>
#include<vector>
using namespace std;

int findPeakElement(vector<int> &nums){
	int l, r, mid;
	l = 0;
	r = nums.size() - 1;
	mid = (l + r) / 2;

	while(l <= r){
		if((mid == 0 || nums[mid - 1] < nums[mid]) && (mid == nums.size() || nums[mid + 1] < nums[mid]))
			return mid;

		else if(nums[mid - 1] < nums[mid])
			l = mid + 1;

		else
			r = mid - 1;

		mid = (l + r) / 2;
	}
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
	result = findPeakElement(nums);

	cout<<result;
}