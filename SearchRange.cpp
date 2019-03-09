#include<iostream>
#include<vector>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target){
	int l, r, mid;
	vector<int> result;

	l = 0;
	r = nums.size()-1;
	mid = (l + r) / 2;

	while(l <= r){
		if(nums[mid] == target){
			if(mid == 0 || nums[mid-1] < target){
				result.push_back(mid);
				break;
			}

			else
				r = mid - 1;
		}

		else if(nums[mid] < target)
			l = mid + 1;

		else
			r = mid - 1;

		mid = (l + r) / 2;
	}

	l = 0; 
	r = nums.size()-1;
	mid = (l + r) / 2;

	while(l <= r){
		if(nums[mid] == target){
			if(mid == nums.size()-1 || nums[mid+1] > target){
				result.push_back(mid);
				break;
			}

			else
				l = mid + 1;
		}

		else if(nums[mid] < target)
			l = mid + 1;

		else
			r = mid - 1;

		mid = (l + r) / 2;
	}

	if(result.empty()){
		result.push_back(-1);
		result.push_back(-1);
	}

	return result;
}

int main(){
	int n, target;
	cin>>n;

	vector<int> arr;
	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		arr.push_back(num);
	}

	cin>>target;

	vector<int> result;
	result = searchRange(arr, target);

	cout<<result[0]<<"\t"<<result[1];
}