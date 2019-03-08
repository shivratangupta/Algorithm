#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int> > fourSum(vector<int> &nums, int target){
	sort(nums.begin(), nums.end());

	vector<vector<int> > result;
	set<vector<int> > setresult;
	int n;
	n = nums.size();

	if(n < 4)
		return result;

	for(int i=0; i<n-3; i++){
		for(int j=i+1; j<n-2; j++){
			int l, r;
			l = j + 1;
			r = n - 1;

			while(l < r){
				int sum;
				sum = nums[i] + nums[j] + nums[l] + nums[r];

				if(sum == target){
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					temp.push_back(nums[l]);
					temp.push_back(nums[r]);
					setresult.insert(temp);
					l++;
					r--;
				}

				else if(sum < target)
					l++;

				else
					r--;
			}
		}
	}

	set<vector<int> > :: iterator it;

	for(it=setresult.begin(); it!=setresult.end(); it++)
		result.push_back(*it);

	return result;
}

int main(){
	int n, target;
	cin>>n;

	vector<int> arr;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		arr.push_back(a);
	}

	cin>>target;

	vector<vector<int> > result;
	result = fourSum(arr, target);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<4; j++){
			cout<<result[i][j]<<"\t";
		}
		cout<<endl;
	}
}
