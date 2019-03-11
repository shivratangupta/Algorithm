#include<iostream>
#include<vector>
#include<set>
using namespace std;

void swap(vector<int> &nums, int i, int j){
	int temp;
	temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void permutation(vector<int> &nums, set<vector<int> > &s, int l, int r){
	if(l == r){
		s.insert(nums);
		return;
	}

	for(int i=l; i<=r; i++){
		swap(nums, l, i);
		permutation(nums, s, l + 1, r);
		swap(nums, l, i);
	}
}

vector<vector<int> > permuteUnique(vector<int> &nums){
	vector<vector<int> > result;

	if(nums.size() == 0)
		return result;

	set<vector<int> > s;

	permutation(nums, s, 0, nums.size()-1);

	set<vector<int> > :: iterator it;

	for(it = s.begin(); it != s.end(); it++)
		result.push_back(*it);

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

	vector<vector<int> > result;
	result = permuteUnique(arr);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<n; j++){
			cout<<result[i][j]<<"\t";
		}
		cout<<endl;
	}
}
