#include<iostream>
using namespace std;

int uniquePaths(int m, int n){
	int result = 1;

	for(int i=n; i<m+n-1; i++){
		result *= i;
		result /= (i-n+1);
	}

	return result;
}

int main(){
	int m, n;
	cin>>m;
	cin>>n;

	int result;
	result = uniquePaths(m, n);

	cout<<result;
}