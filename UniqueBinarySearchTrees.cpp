#include<iostream>
using namespace std;

long long int totalTrees(int n, int k){
	long long int result;
	result = 1;

	if(k > n - k)
		k = n - k;

	for(int i=0; i<k; i++){
		result *= (n - i);
		result /= (i + 1);
	}

	return result;
}

int numTrees(int n){
	long long int result;

	result = totalTrees(2 * n, n);

	return result / (n + 1);
}

int main(){
	int n;
	cin>>n;

	int result;
	result = numTrees(n);

	cout<<result;
}
