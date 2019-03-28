#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int minCut(string s){
	int n;
	n = s.size();

	vector<vector<bool> > pal(n, vector<bool> (n, false));
	vector<int> cut(n);

	for(int i=0; i<n; i++)
		pal[i][i] = true;

	for(int l=2; l<=n; l++){
		for(int i=0; i<n - l + 1; i++){
			int j;
			j = i + l - 1;

			if(l == 2){
				if(s[i] == s[j])
					pal[i][j] = true;
			}

			else if(pal[i + 1][j - 1] == true && s[i] == s[j])
				pal[i][j] = true;

			else
				pal[i][j] = false;
		}
	}

	for(int i=0; i<n; i++){
		if(pal[0][i] == true)
			cut[i] = 0;

		else{
			cut[i] = INT_MAX;
			for(int j=0; j<i; j++){
				if(pal[j + 1][i] == true)
					cut[i] = min(cut[i], cut[j] + 1);
			}
		}
	}

	return cut[n - 1];
}

int main(){
	string s;
	cin>>s;

	int result;
	result = minCut(s);

	cout<<result;
}
