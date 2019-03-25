#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> &prices){
	int profit;
	profit = 0;

	if(prices.size() == 0)
		return profit;

	for(int i=0; i<prices.size()-1; i++){
		if(prices[i] < prices[i + 1])
			profit += prices[i + 1] - prices[i];
	}

	return profit;
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