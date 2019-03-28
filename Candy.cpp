#include<iostream>
#include<vector>
using namespace std;

int candy(vector<int> &ratings){
	int n, i;
	n = ratings.size();
	i = 0;

	vector<int> result(n, 1);

	while(i < n){
		if(i == 0){
			if(ratings[i] > ratings[i + 1])
				result[i] = result[i + 1] + 1;
		}

		else if(i == n - 1){
			if(ratings[i] > ratings[i - 1])
				result[i] = result[i - 1] + 1;
		}

		else{
			if(ratings[i] > ratings[i - 1] && ratings[i] > ratings[i + 1])
				result[i] = max(result[i - 1], result[i + 1]) + 1;

			else if(ratings[i] > ratings[i - 1])
				result[i] = result[i - 1] + 1;

			else if(ratings[i] > ratings[i + 1])
				result[i] = result[i + 1] + 1;
		}

		i++;
	}

	i = n - 1;

	while(i >= 0){
		if(i == 0){
			if(ratings[i] > ratings[i + 1])
				result[i] = result[i + 1] + 1;
		}

		else if(i == n - 1){
			if(ratings[i] > ratings[i - 1])
				result[i] = result[i - 1] + 1;
		}	

		else{
			if(ratings[i] > ratings[i - 1] && ratings[i] > ratings[i + 1])
				result[i] = max(result[i - 1], result[i + 1]) + 1;

			else if(ratings[i] > ratings[i - 1])
				result[i] = result[i - 1] + 1;

			else if(ratings[i] > ratings[i + 1])
				result[i] = result[i + 1] + 1;
		}

		i--;
	}

	int count;
	count = 0;

	for(int i=0; i<n; i++)
		count += result[i];

	return count;
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
	result = candy(arr);

	cout<<result;
}
