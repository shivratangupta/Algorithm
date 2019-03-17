#include<iostream>
#include<vector>
using namespace std;

bool search(vector<int> &nums, int target){
	int l, r, mid;
	l = 0;
	r = nums.size() - 1;
	mid = (l + r) / 2;

	while(l <= r){
		if(nums[mid] == target)
			return true;

		else if(nums[l] == nums[mid] && nums[mid] == nums[r]){
			l++;
			r--;
		}

		else if(nums[l] <= nums[mid]){
			if(target >= nums[l] && target <= nums[mid])
				r = mid - 1;

			else
				l = mid + 1;
		}

		else{
			if(target >= nums[mid] && target <= nums[r])
				l = mid + 1;

			else
				r = mid - 1;
		}

		mid = (l + r) / 2;
	}

	return false;
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

	bool result;
	result = search(arr, target);

	cout<<result;
}