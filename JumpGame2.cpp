#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int jump(vector<int> &nums){
	int n;
	n = nums.size(); 

	if(n <= 1)
		return 0;

	if(nums[0] == 0)
		return -1;

	int maxreach, step, jump;
	maxreach = nums[0];
	step = nums[0];
	jump = 1;

	for(int i=1; i<n; i++){
		if(i == n - 1)
			return jump;

		maxreach = max(maxreach, i + nums[i]);

		step--;

		if(step == 0){
			jump++;

			if(i >= maxreach)
				return -1;

			step = maxreach - i;
		}
	}

	return -1;
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
	result = jump(arr);

	cout<<result;
}