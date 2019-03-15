#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int> &nums){
	if(nums.size() == 0)
		return 0;

	int n, j;
	n = nums.size();
	j = 0;

	for(int i=0; i<n; i++){
		if(i < n - 2 && nums[i] == nums[i + 1] && nums[i] == nums[i + 2])
			continue;

		else{
			nums[j] = nums[i];
			j++;
		}
	}

	return j;
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