#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &nums, int i, int j){
	int temp;
	temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void sortColors(vector<int> &nums){
	int x, y, z;
	x = 0;
	y = 0;
	z = nums.size() - 1;

	while(y <= z){
		if(nums[y] == 0){
			swap(nums, x, y);
			x++;
			y++;
		}

		else if(nums[y] == 1)
			y++;

		else{
			swap(nums, y, z);
			z--;
		}
	}
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

	sortColors(arr);

	for(int i=0; i<n; i++)
		cout<<arr[i]<<"\t";
}
