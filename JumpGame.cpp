#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

bool canJump(vector<int> &nums){
	vector<int> dp(nums.size(), 0);

	if(nums.size() == 1)
		return true;

	dp[0] = 0;

	for(int i=1; i<nums.size(); i++){
		dp[i] = INT_MAX;
		for(int j=0; j<i; j++){
			if(i <= j + nums[j] && dp[j] != INT_MAX){
				dp[i] = min(dp[i], dp[j] + 1);
				break;
			}
		}
	}

	if(dp[nums.size()-1] == INT_MAX)
		return false;

	else
		return true;
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

	bool result;
	result = canJump(arr);

	cout<<result;
}