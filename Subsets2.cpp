#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<vector<int> > subsetsWithDup(vector<int> &nums){
	vector<vector<int> > result(1, vector<int> (0));

	for(int i=0; i<nums.size(); i++){
		int n;
		n = result.size();

		for(int j=0; j<n; j++){
			vector<int> temp(result[j].begin(), result[j].end());
			temp.push_back(nums[i]);
			result.push_back(temp);
		}
	}

	set<vector<int> > s;

	for(int i=0; i<result.size(); i++)
		s.insert(result[i]);

	result.clear();
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
	result = subsetsWithDup(arr);

	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++){
			cout<<result[i][j]<<"\t";
		}
		cout<<endl;
	}
}
