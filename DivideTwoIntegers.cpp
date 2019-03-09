#include<iostream>
#include<limits.h>
#include<stdlib.h>
using namespace std;

int divide(int dividend, int divisor){
	if(divisor == 0)
		return INT_MAX;

	if(divisor == -1 && dividend == INT_MAX)
		return INT_MIN;

	if(divisor == -1 && dividend == INT_MIN)
		return INT_MAX;

	if(divisor == 1 && dividend == INT_MAX)
		return INT_MAX;

	if(divisor == 1 && dividend == INT_MIN)
		return INT_MIN;

	bool neg = false;
	if((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0))
		neg = true;

	long dividend1, divisor1;
	dividend1 = abs(dividend);
	divisor1 = abs(divisor);
	long quotient, currdiv, currqub;
	quotient = 0;
	currdiv = divisor1;
	currqub = 1;

	while(dividend1 >= divisor1){
		if(dividend1 >= currdiv){
			dividend1 -= currdiv;
			quotient += currqub;

			currdiv *= 2;
			currqub *= 2;
		}

		else{
			currdiv /= 2;
			currqub /= 2;
		}
	}

	if(neg)
		quotient = -quotient;

	return quotient;
}

int main(){
	int dividend, divisor;
	cin>>dividend;
	cin>>divisor;

	int quotient;
	quotient = divide(dividend, divisor);

	cout<<quotient;
}
