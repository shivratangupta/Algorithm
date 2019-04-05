#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
	vector<int> result;
	int i, j;
	i = 0;
	j = nums.size() - 1;

	while(i < j){
		if(nums[i] + nums[j] == target){
			result.push_back(i + 1);
			result.push_back(j + 1);
			return result;
		}

		else if(nums[i] + nums[j] < target)
			i++;

		else
			j--;
	}
}

int main(){
	int n, target;
	cin>>n;

	vector<int> nums;
	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		nums.push_back(num);
	}

	cin>>target;

	vector<int> result;
	result = twoSum(nums, target);

	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<"\t";
}