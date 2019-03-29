#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int> &nums){
	if(nums.size() == 0)
		return 0;

	int result;
	result = nums[0];

	for(int i=1; i<nums.size(); i++)
		result = result ^ nums[i];

	return result;
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
	result = singleNumber(arr);

	cout<<result;
}
