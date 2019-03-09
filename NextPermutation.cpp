#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int> &nums, int i, int j){
	while(i < j){
		int temp;
		temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
		i++;
		j--;
	}

	return;
}

void nextPermutation(vector<int> &nums){
	int i;
	i = nums.size()-2;

	while(i >= 0 && nums[i] >= nums[i+1])
		i--;

	if(i < 0){
		reverse(nums, 0, nums.size()-1);
		return;
	}

	int j;
	j = i + 1;

	for(int k=i+1; k<nums.size(); k++){
		if(nums[k] > nums[i])
			j = k;
	}

	int temp;
	temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;

	reverse(nums, i+1, nums.size()-1);

	return;
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

	nextPermutation(arr);

	for(int i=0; i<n; i++)
		cout<<arr[i]<<"\t";
}
