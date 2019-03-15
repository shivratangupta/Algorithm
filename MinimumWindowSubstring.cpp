#include<iostream>
#include<string.h>
#include<map>
#include<limits.h>
using namespace std;

string minWindow(string s, string t){
	int m, n, count, st, start, length;
	m = s.size();
	n = t.size();

	map<char, int> str;
	map<char, int> ptr;

	for(int i=0; i<n; i++)
		ptr[t[i]]++;

	count = 0;
	st = 0;
	start = -1;
	length = INT_MAX;

	for(int i=0; i<m; i++){
		str[s[i]]++;

		if(ptr.find(s[i]) != ptr.end() && str[s[i]] <= ptr[s[i]])
			count++;

		if(count == n){
			while(ptr.find(s[st]) == ptr.end() || str[s[st]] > ptr[s[st]]){
				if(str[s[st]] > ptr[s[st]])
					str[s[st]]--;

				st++;
			}

			int len;
			len = i - st + 1;
			if(length > len){
				length = len;
				start = st;
			}
		}
	}

	if(start == -1)
		return "";

	return s.substr(start, length);
}

int main(){
	string s, t;
	cin>>s;
	cin>>t;

	string result;
	result = minWindow(s, t);

	cout<<result;
}
