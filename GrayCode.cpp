#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int binaryToDecimal(string s){
	int result, i, j;
	i = s.size()-1;
	j = 0;
	result = 0;

	while(i >= 0){
		if(s[i] == '1')
			result += pow(2, j);

		i--;
		j++;
	}

	return result;
}

vector<int> grayCode(int n){
	vector<int> result;

	if(n < 0)
		return result;

	result.push_back(0);
	if(n == 0)
		return result;

	vector<string> arr;
	arr.push_back("0");
	arr.push_back("1");

	result.push_back(1);

	for(int i=2; i<=n; i++){
		vector<string> arr1;
		arr1 = arr;
		reverse(arr.begin(), arr.end());

		for(int j=0; j<arr1.size(); j++){
			arr1[j].insert(0, "0");
			arr[j].insert(0, "1");
		}

		for(int j=0; j<arr.size(); j++){
			int k;
			k = binaryToDecimal(arr[j]);
			result.push_back(k);
		}

		arr.insert(arr.begin(), arr1.begin(), arr1.end());
	}

	return result;
}

int main(){
	int n;
	cin>>n;

	vector<int> result;
	result = grayCode(n);

	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<"\t";
}