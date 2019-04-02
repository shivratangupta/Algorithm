#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int> &nums){
	int l, r, mid, n;
	n = nums.size();
	l = 0;
	r = n - 1;
	mid = (l + r) / 2;

	while(l < r){
		if(nums[mid] > nums[r])
			l = mid + 1;

		else if(nums[mid] < nums[r])
			r = mid;

		else
			r--;

		mid = (l + r) / 2;
	}

	return nums[l];
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
