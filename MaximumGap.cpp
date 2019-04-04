#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int maximumGap(vector<int> &nums){
	if(nums.size() < 2)
		return 0;

	int minval, maxval, n;
	n = nums.size();
	minval = nums[0];
	maxval = nums[0];

	for(int i=1; i<n; i++){
		minval = min(minval, nums[i]);
		maxval = max(maxval, nums[i]);
	}

	int d;
	d = (maxval - minval) / (n - 1);

	if(d == 0)
		d = 1;

	int size;
	size = (maxval - minval) / d + 1;

	vector<int> max1(size, INT_MIN);
	vector<int> min1(size, INT_MAX);

	for(int i=0; i<n; i++){
		int index;
		index = (nums[i] - minval) / d;

		max1[index] = max(max1[index], nums[i]);
		min1[index] = min(min1[index], nums[i]);
	}

	int prevmax, maxgap;
	prevmax = minval;
	maxgap = 0;
	for(int i=0; i<size; i++){
		if(min1[i] == INT_MAX)
			continue;

		maxgap = max(maxgap, min1[i] - prevmax);
		prevmax = max1[i];
	}

	return maxgap;
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
	result = maximumGap(nums);

	cout<<result;
}
