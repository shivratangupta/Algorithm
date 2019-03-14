#include<iostream>
using namespace std;

int mySqrt(int x){
	if(x == 1)
		return 1;

	long long l, r, mid;
	l = 0;
	r = x / 2;
	mid = (l + r) / 2;

	while(l <= r){
		if(mid * mid <= x && (mid + 1) * (mid + 1) > x)
			return mid;

		else if(mid * mid < x)
			l = mid + 1;

		else
			r = mid - 1;

		mid = (l + r) / 2;
	}
}

int main(){
	int n;
	cin>>n;

	int result;
	result = mySqrt(n);

	cout<<result;
}