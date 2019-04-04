#include<iostream>
#include<string.h>
using namespace std;

int compareVersion(string version1, string version2){
	int m, n, i, j;
	m = version1.size();
	n = version2.size();
	i = 0;
	j = 0;

	while(i < m || j < n){
		int a, b;
		a = 0;
		b = 0;

		while(i < m && version1[i] != '.'){
			a = a * 10 + (version1[i] - '0');
			i++;
		}

		while(j < n && version2[j] != '.'){
			b = b * 10 + (version2[j] - '0');
			j++;
		}

		if(a > b)
			return 1;

		else if(a < b)
			return -1;

		if(i < m && version1[i] == '.')
			i++;

		if(j < n && version2[j] == '.')
			j ++;
	}

	return 0;
}

int main(){
	string version1, version2;

	cin>>version1;
	cin>>version2;

	int result;
	result = compareVersion(version1, version2);

	cout<<result;
}