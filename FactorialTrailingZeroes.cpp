#include<iostream>
using namespace std;

int trailingZeroes(int n){
	int count;
	long long int x;
	count = 0;
	x = 5;

	while(x <= n){
		count += (n / x);
		x *= 5;
	}

	return count;
}

int main(){
	int n;
	cin>>n;

	int result;
	result = trailingZeroes(n);

	cout<<result;
}