#include<iostream>
#include<limits.h>
using namespace std;

int reverse(int x){
	bool neg;
	neg = false;

	if(x < 0){
		neg = true;
		x = -x;
	}

	int result;
	result = 0;

	while(x > 0){
		result = result * 10 + x % 10;
		x /= 10;
	}

	if(neg)
		result = -result;

	if(result > INT_MAX || result < INT_MIN)
		return 0;

	return result;
}

int main(){
	int n;
	cin>>n;

	int result;

	result = reverse(n);

	cout<<result;
}