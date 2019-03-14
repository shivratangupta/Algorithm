#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

string addBinary(string a, string b){
	int i, j, m, n, carry;
	m = a.size();
	n = b.size();
	i = m - 1;
	j = n - 1;
	carry = 0;

	string result = "";

	while(i >= 0 || j >= 0){
		int x, y, sum;

		if(i < 0)
			x = 0;

		else
			x = a[i] - '0';

		if(j < 0)
			y = 0;

		else
			y = b[j] - '0';

		sum = x + y + carry;

		if(sum == 0)
			result += '0';

		else if(sum == 1){
			result += '1';
			carry = 0;
		}

		else if(sum == 2){
			result += '0';
			carry = 1;
		}

		else{
			result += '1';
			carry = 1;
		}

		i--;
		j--;
	}

	if(carry == 1)
		result += '1';

	reverse(result.begin(), result.end());

	return result;
}

int main(){
	string a, b;
	cin>>a;
	cin>>b;

	string result;
	result = addBinary(a, b);

	cout<<result;
}