#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int> &nums){
	if(nums.size() == 0)
		return 0;

	int j;
	j = 0;

	for(int i=0; i<nums.size()-1; i++){
		if(nums[i] != nums[i+1]){
			nums[j] = nums[i];
			j++;
		}
	}

	nums[j] = nums[nums.size()-1];

	return j + 1;
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
	result = removeDuplicates(arr);

	cout<<result;
}