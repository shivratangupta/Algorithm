#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

string LongestSubstringWRC(string s){
	int start, length, st, currlen;

	map<char, int> m;
	st = 0;
	length = 0;

	for(int i=0; i<s.size(); i++){
		if(m.find(s[i]) == m.end())
			m[s[i]] = i;

		else{
			if(m[s[i]] >= st){
				currlen = i - st;
				if(currlen > length){
					length = currlen;
					start = st;
				}

				st = m[s[i]] + 1;
			}

			m[s[i]] = i;
		}
	}

	if(s.size() - st > length){
		length = s.size() - st;
		start = st;
	}

	string result;
	result = s.substr(start, length);

	return result;
}



int main(){
	string s;
	cin>>s;

	string result;
	result = LongestSubstringWRC(s);

	cout<<result;
}