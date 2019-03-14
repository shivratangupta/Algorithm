#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> plusOne(vector<int> &digit){
	vector<int> result;

	int carry, n, sum;
	n = digit.size();
	sum = digit[n - 1] + 1;
	carry = sum / 10;
	result.push_back(sum % 10);

	for(int i=n-2; i>=0; i--){
		sum = digit[i] + carry;
		carry = sum / 10;
		result.push_back(sum % 10);
	}

	if(carry > 0)
		result.push_back(carry);

	reverse(result.begin(), result.end());

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

	vector<int> result;
	result = plusOne(arr);

	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<"\t";
}
