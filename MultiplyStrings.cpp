#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

string multiply(string num1, string num2){
	int n1, n2;
	n1 = num1.size();
	n2 = num2.size();

	if(n1 == 0 || n2 == 0)
		return "0";

	vector<int> result(n1 + n2, 0);

	int x, y;
	x = 0;
	y = 0;

	for(int i=n1-1; i>=0; i--){
		int a, carry;
		a = num1[i] - '0';
		carry = 0;
		y = 0;

		for(int j=n2-1; j>=0; j--){
			int b, sum;
			b = num2[j] - '0';

			sum = a * b + result[x + y] + carry;
			carry = sum / 10;
			result[x + y] = sum % 10;

			y++;
		}

		if(carry > 0)
			result[x + y] += carry;

		x++;
	}

	int i;
	i = result.size() -1;

	while(i >= 0 && result[i] == 0)
		i--;

	if(i < 0)
		return "0";

	string s = "";

	while(i >= 0){
		s += result[i] + '0';
		i--;
	}

	return s;
}

int main(){
	string s1, s2;
	cin>>s1;
	cin>>s2;

	string result;
	result = multiply(s1, s2);

	cout<<result;
}
