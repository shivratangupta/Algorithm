#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int maxProfit(vector<int> &prices){
	if(prices.size() == 0)
		return 0;

	int m, n;
	m = 2;
	n = prices.size();

	vector<vector<int> > profit(m + 1, vector<int> (n));

	for(int i=0; i<=2; i++){
		int prevDiff = INT_MIN;
		for(int j=0; j<n; j++){
			if(i == 0)
				profit[i][j] = 0;

			else if(j == 0)
				profit[i][j] = 0;

			else{
				prevDiff = max(prevDiff, profit[i - 1][j - 1] - prices[j - 1]);
				profit[i][j] = max(profit[i][j - 1], prices[j] + prevDiff);
			}
		}
	}

	return profit[m][n - 1];
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