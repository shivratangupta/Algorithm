#include<iostream>
#include<vector>
#include<string.h>
#include<stdlib.h>
using namespace std;

vector<string> restoreIpAddresses(string s){
	vector<string> result;
	int n;
	n = s.size();

	for(int i=1; i<=3; i++){
		for(int j=1; j<=3; j++){
			for(int k=1; k<=3; k++){
				for(int l=1; l<=3; l++){
					if(i + j + k + l == n){
						int A, B, C, D;
						A = stoi(s.substr(0, i));
						B = stoi(s.substr(i, j));
						C = stoi(s.substr(i+j, k));
						D = stoi(s.substr(i+j+k, l));

						if(A <= 255 && B <= 255 && C <= 255 && D <= 255){
							string temp;
							temp = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);

							if(temp.size() == n + 3)
								result.push_back(temp);
						}
					}
				}
			}
		}
	}

	return result;
}

int main(){
	string s;
	cin>>s;

	vector<string> result;
	result = restoreIpAddresses(s);

	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<"\t";
}
