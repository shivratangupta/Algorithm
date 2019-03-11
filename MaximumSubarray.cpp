#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int> &nums){
	int curr, best;
	curr = nums[0];
	best = nums[0];

	for(int i=1; i<nums.size(); i++){
		curr = max(curr + nums[i], nums[i]);
		best = max(curr, best);
	}

	return best;
}

int main(){
	int n;
	cin>>n;

	vector<int> arr;
	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		arr.push_back(num);
	}

	int result;
	result = maxSubArray(arr);

	cout<<result;
}
