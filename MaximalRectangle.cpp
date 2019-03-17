#include<iostream>
#include<vector>
#include<stack>
#include<string.h>
using namespace std;

int maximalRectangle(vector<vector<char> > &matrix){
	int m, n;
	m = matrix.size();

	if(m == 0)
		return 0;
	
	n = matrix[0].size();

	if(n == 0)
		return 0;

	vector<vector<int> > arr(m, vector<int> (n, 0));

	for(int j=0; j<n; j++)
		arr[0][j] = matrix[0][j] - '0';

	for(int i=1; i<m; i++){
		for(int j=0; j<n; j++){
			if(matrix[i][j] == '1')
				arr[i][j] = (matrix[i][j] - '0') + arr[i - 1][j];
		}
	}

	int max, rect;
	max = 0;

	for(int i=0; i<m; i++){
		stack<int> s;
		int j;
		j = 0;

		while(j < n){
			if(s.empty() || arr[i][j] >= arr[i][s.top()]){
				s.push(j);
				j++;
			}

			else{
				int k, width;
				k = s.top();
				s.pop();

				if(s.empty())
					width = j;

				else
					width = j - s.top() - 1;

				rect = arr[i][k] * width;
				if(rect > max)
					max = rect; 
			}
		}

		while(!s.empty()){
			int k, width;
			k = s.top();
			s.pop();

			if(s.empty())
				width = j;

			else
				width = j - s.top() - 1;

			rect = arr[i][k] * width;
			if(rect > max)
				max = rect;
		}
	}

	return max;
}

int main(){
	int m, n;
	cin>>m;
	cin>>n;

	vector<vector<char> > matrix(m, vector<char> (n));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			char c;
			cin>>c;
			matrix[i][j] = c;
		}
	}

	int result;
	result = maximalRectangle(matrix);

	cout<<result;
}