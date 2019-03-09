#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int> &nums, int val){
	int i, j, count;
	i = 0;
	j = 0;
	count = 0;

	while(i < nums.size()){
		if(nums[i] != val){
			count++;
			int temp;
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			j++;
		}
		
		i++;
	}

	return count;
}

int main(){
	int n, val;
	cin>>n;

	vector<int> arr;
	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		arr.push_back(num);
	}

	cin>>val;

	int result;
	result = removeElement(arr, val);

	cout<<result;
}