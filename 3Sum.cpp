#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int> &nums){
	sort(nums.begin(), nums.end());
	int n;
	n = nums.size();
	vector<vector<int> > result;
	vector<int> arr(n);

	if(nums == arr && !nums.empty() && n >= 3){
		vector<int> temp(3);
		result.push_back(temp);
		return result;
	}

	for(int i=0; i<n-2; i++){
		int l, r;
		l = i + 1;
		r = n - 1;

		while(l < r){
			if(nums[i] + nums[l] + nums[r] == 0){
				vector<int> temp;
				temp.push_back(nums[i]);
				temp.push_back(nums[l]);
				temp.push_back(nums[r]);
				result.push_back(temp);
				l++;
				r--;
			}

			else if(nums[i] + nums[l] + nums[r] < 0)
				l++;

			else
				r--;
		}
	}

	sort(result.begin(), result.end());

	vector<vector<int> > result1;
	result1.push_back(result[0]);

	int j = 0;

	for(int i=1; i<result.size(); i++){
		if(result[i] != result1[j]){
			result1.push_back(result[i]);
			j++;
		}
	}

	return result1;
}

int main(){
	int n;
	cin>>n;

	vector<int> arr;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		arr.push_back(a);
	}

	vector<vector<int> > result;
	result = threeSum(arr);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<3; j++){
			cout<<result[i][j]<<"\t";
		}
		cout<<endl;
	}
}
