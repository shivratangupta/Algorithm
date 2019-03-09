#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int> &nums, int target){
	int l, r, mid;
	l = 0;
	r = nums.size() - 1;
	mid = (l + r) / 2;

	while(l <= r){
		if(mid == 0 && target <= nums[mid])
			return mid;

		else if(mid == nums.size()-1 && target > nums[mid])
			return mid + 1;

		else if(nums[mid] < target && nums[mid+1] >= target)
			return mid + 1;

		else if(nums[mid] < target)
			l = mid + 1;

		else
			r = mid - 1;

		mid = (l + r) / 2;
	}
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

	int result;
	result = searchInsert(arr, target);

	cout<<result;
}