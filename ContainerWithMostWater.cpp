#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int> &height){
	int area, i, j;
	area = 0;
	i = 0;
	j = height.size()-1;

	while(i < j){
		int x;
		x = min(height[i], height[j]);
		area = max(area, x * (j - i));
		
		if(height[i] < height[j])
			i++;

		else
			j--;
	}

	return area;
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

	int result;
	result = maxArea(arr);

	cout<<result;
}