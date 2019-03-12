#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > generateMatrix(int n){
	vector<vector<int> > result(n, vector<int> (n, 0));

	int i, j, x, y, num;
	i = 0;
	j = 0;
	x = n;
	y = n;
	num = 1;

	while(i < x && j < y){
		for(int k=j; k<y; k++){
			result[i][k] = num;
			num++;
		}

		i++;

		for(int k=i; k<x; k++){
			result[k][y-1] = num;
			num++;
		}

		y--;

		if(i < x){
			for(int k=y-1; k>=j; k--){
				result[x-1][k] = num;
				num++;
			}
			x--;
		}

		if(j < y){
			for(int k=x-1; k>=i; k--){
				result[k][j] = num;
				num++;
			}
			j++;
		}
	}

	return result;
}

int main(){
	int n;
	cin>>n;

	vector<vector<int> > result;
	result = generateMatrix(n);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<result[i][j]<<"\t";
		}
		cout<<endl;
	}
}