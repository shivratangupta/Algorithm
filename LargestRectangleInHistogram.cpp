#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int> &heights){
	stack<int> s;
	int n, i, max, rect;
	n = heights.size();
	i = 0;
	max = 0;

	while(i < n){
		if(s.empty() || heights[i] >= heights[s.top()]){
			s.push(i);
			i++;
		}

		else{
			int j, width;
			j = s.top();
			s.pop();

			if(s.empty())
				width = i;

			else
				width = i - s.top() - 1;

			rect = heights[j] * width;
			if(rect > max)
				max = rect;
		}
	}

	while(!s.empty()){
		int j, width;
		j = s.top();
		s.pop();

		if(s.empty())
			width = i;

		else
			width = i - s.top() - 1;

		rect = heights[j] * width;
		if(rect > max)
			max = rect;
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
	result = largestRectangleArea(arr);

	cout<<result;
}
