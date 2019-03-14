#include<iostream>
using namespace std;

int climbStairs(int n){
	int a, b, c;
	a = 1;
	b = 1;
	c = 1;

	for(int i=1; i<n; i++){
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}

int main(){
	int n;
	cin>>n;

	int result;
	result = climbStairs(n);

	cout<<result;
}