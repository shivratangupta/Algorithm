#include<iostream>
#include<limits.h>
#include<string.h>
#include<math.h>
using namespace std;

string fractionToDecimal(int numerator, int denominator){
	if(numerator == INT_MAX && denominator == 1)
		return to_string(INT_MAX);

	if(numerator == INT_MAX && denominator == -1)
		return to_string(INT_MIN);

	if(numerator == INT_MIN && denominator == 1)
		return to_string(INT_MIN);

	if(numerator == INT_MIN && denominator == -1)
		return to_string(INT_MIN).substr(1, to_string(INT_MIN).size());

	string result;
	map<int, int> m;
	int a;

	if(((numerator > 0 && denominator < 0) || (numerator < 0 && denominator)) && (numerator < denominatro))
		result += "-";

	a = numerator / denominator;

	result += tor_string(a);

	if(numerator % denominator != 0){
		result += ".";
		long long int a;
		a = numerator;

		while(a % denominator != 0){
			a = a % denominator;

			if(m.find(a) == m.end()){
				m[a] = result.size();
				a = a * 10;
				long long int b;
				b = a / denominator;
				if(b < 0)
					b = -b;
				result += to_string(b);
			}

			else{
				result.insert(m[a], "(");
				result.push_back(")");
				break;
			}
		}
	}
}

int main(){
	int numerator, denominator;
	cin>>numerator;
	cin>>denominator;

	string result;
	result = fractionToDecimal(numerator, denominator);

	cout<<result;
}