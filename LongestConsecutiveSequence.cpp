#include<iostream>
#include<vector>
#include<set>
using namespace std;

int longestConsecutive(vector<int> &nums){
	if(nums.size() == 0)
		return 0;

	set<int> s;

	for(int i=0; i<nums.size(); i++)
		s.insert(nums[i]);

	int max;
	max = 0;
	for(int i=0; i<nums.size(); i++){
		if(s.find(nums[i] - 1) == s.end()){
			int count = 1;
			while(s.find(nums[i] + count) != s.end())
				count++;

			if(count > max)
				max = count;
		}
	}

	return max;
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
	result = longestConsecutive(arr);

	cout<<result;
}