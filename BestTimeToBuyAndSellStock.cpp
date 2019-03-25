#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> &prices){
	int maxprofit, min1;
	maxprofit = 0;

	if(prices.size() == 0)
		return maxprofit;
	
	min1 = prices[0];

	for(int i=1; i<prices.size(); i++){
		min1 = min(min1, prices[i]);
		maxprofit = max(maxprofit, prices[i] - min1);
	}

	return maxprofit;
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
	result = maxProfit(arr);

	cout<<result;
}