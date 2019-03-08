// 1/n!

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
using namespace std;

void swap(vector<int> &arr, int i, int j){
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int main(){
	int n;
	cin>>n;
	
	vector<int> arr;
	
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		arr.push_back(a);
	}
	
	srand(time(NULL));
	
	for(int i=n-1; i>=0; i--){
		int j;
		j = rand() % (i+1);
		
		swap(arr, i, j);
	}
	
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}
