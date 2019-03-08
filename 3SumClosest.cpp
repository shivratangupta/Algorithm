#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int threeSumClosest(vector<int> &nums, int target){
	sort(nums.begin(), nums.end());

	int result, n;
	result = nums[0] + nums[1] + nums[2];

	n = nums.size();
	for(int i=0; i<n; i++){
		int l, r;
		l = i + 1;
		r = n - 1;

		while(l < r){
			int sum;
			sum = nums[i] + nums[l] + nums[r];

			if(sum == target)
				return sum;

			if(abs(sum - target) < abs(result - target))
				result = sum;

			else if(sum < target)
				l++;

			else
				r--;
		}
	}

	return result;
}

int main(){
	int n, target;
	cin>>n;

	vector<int> arr;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		arr.push_back(a);
	}

	cin>>target;

	int result;
	result = threeSumClosest(arr, target);

	cout<<result;
}