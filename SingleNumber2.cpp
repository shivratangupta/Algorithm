#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int> &nums){
	if(nums.size() == 0)
		return 0;

	int num1, num2;
	num1 = 0;
	num2 = 0;

	for(int i=0; i<nums.size(); i++){
		num1 = (num1 ^ nums[i]) & ~num2;
		num2 = (num2 ^ nums[i]) & ~num1;
	}

	return num1;
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