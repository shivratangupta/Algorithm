#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int> &height){
	int n, result;
	n = height.size();
	result = 0;

	if(n == 0)
		return 0;

	vector<int> left(n);
	vector<int> right(n);

	left[0] = height[0];
	for(int i=1; i<n; i++)
		left[i] = max(height[i], left[i-1]);

	right[n-1] = height[n-1];
	for(int i=n-2; i>=0; i--)
		right[i] = max(height[i], right[i+1]);

	for(int i=0; i<n; i++)
		result += min(left[i], right[i]) - height[i];

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

	int result;
	result = trap(arr);

	cout<<result;
}