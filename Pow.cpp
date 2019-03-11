#include<iostream>
using namespace std;

double myPow(double x, int n){
	if(n == 0)
		return 1;

	double temp;
	temp = myPow(x, n/2);

	if(n % 2 == 0)
		return temp * temp;

	else{
		if(n > 0)
			return x * temp * temp;

		else
			return 1/x * temp * temp;
	}
}

int main(){
	double x;
	int n;
	cin>>x;
	cin>>n;

	double result;
	result = myPow(x, n);

	cout<<result;
}