#include<iostream>
#include<string.h>
using namespace std;

int strStr(string haystack, string needle){
	int m, n;
	m = haystack.size();
	n = needle.size();

	if(m < n)
		return -1;

	if(n == 0)
		return 0;

	for(int i=0; i<m; i++){
		if(haystack[i] == needle[0] && m - i >= n && haystack.substr(i, n) == needle)
			return i;
	}

	return -1;
}

int main(){
	string haystack, needle;
	cin>>haystack;
	cin>>needle;

	int result;
	result = strStr(haystack, needle);

	cout<<result;
}