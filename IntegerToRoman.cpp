#include<iostream>
#include<string.h>
using namespace std;

void addRoman(string &result, int n, char c){
	for(int i=0; i<n; i++){
		result += c;
	}
}

string intToRoman(int num){
	string result="";

	while(num > 0){
		if(num >= 1000){
			int a;
			a = num / 1000;
			addRoman(result, a, 'M');
			num %= 1000;
		}

		else if(num >= 500){
			if(num < 900){
				addRoman(result, 1, 'D');
				num %= 500;
			}

			else{
				addRoman(result, 1, 'C');
				addRoman(result, 1, 'M');
				num %= 100;
			}
		}

		else if(num >= 100){
			if(num < 400){
				int a;
				a = num / 100;
				addRoman(result, a, 'C');
				num %= 100;
			}

			else{
				addRoman(result, 1, 'C');
				addRoman(result, 1, 'D');
				num %= 100;
			}
		}

		else if(num >= 50){
			if(num < 90){
				addRoman(result, 1, 'L');
				num %= 50;
			}

			else{
				addRoman(result, 1, 'X');
				addRoman(result, 1, 'C');
				num %= 10;
			}
		}

		else if(num >= 10){
			if(num < 40){
				int a;
				a = num / 10;
				addRoman(result, a, 'X');
				num %= 10;
			}

			else{
				addRoman(result, 1, 'X');
				addRoman(result, 1, 'L');
				num %= 10;
			}
		}

		else if(num >= 5){
			if(num < 9){
				addRoman(result, 1, 'V');
				num %= 5;
			}

			else{
				addRoman(result, 1, 'I');
				addRoman(result, 1, 'X');
				num = 0;
			}
		}

		else{
			if(num < 4){
				int a;
				a = num;
				addRoman(result, a, 'I');
				num = 0;
			}

			else{
				addRoman(result, 1, 'I');
				addRoman(result, 1, 'V');
				num = 0;
			}
		}
	}

	return result;
}

int main(){
	int num;
	cin>>num;

	string result;
	result = intToRoman(num);

	cout<<result;
}