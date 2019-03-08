#include<iostream>
#include<string.h>
#include<limits.h>
using namespace std;

int myAtoi(string str){
	int result, i, n;
	bool neg;
	i = 0;
	neg = false;
	n = str.size();
	result = 0;

	while(i<n && str[i] == ' ')
		i++;

	if(str[i] >= 'a' && str[i] <= 'z')
		return 0;

	else if(str[i] == '-'){
		neg = true;
		i++;
	}

	else if(str[i] == '+')
		i++;

	while(i<n && isdigit(str[i])){
		if(result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - 48 > INT_MAX % 10)){
			if(neg)
				return INT_MIN;

			else
				return INT_MAX;
		}

		result = result * 10 + (str[i] - 48);
		i++;
	}

	if(neg)
		result = -result;

	return result;

}

int main(){
	string s;
	cin>>s;

	int result;

	result = myAtoi(s);

	cout<<result;
}