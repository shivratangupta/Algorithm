#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int> &nums){
	if(nums.size() == 1)
		return nums[0];

	int l, r, mid, n;
	n = nums.size();
	l = 0;
	r = n - 1;
	mid = (l + r) / 2;

	while(l <= r){
		if(nums[(mid + 1) % n] > nums[mid] && nums[(mid - 1) % n] > nums[mid])
			return nums[mid];

		else if(nums[mid] > nums[n - 1])
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
	result = findMin(nums);

	cout<<result;
}