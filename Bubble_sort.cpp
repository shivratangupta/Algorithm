#include<iostream>
using namespace std;

int main(){
	int n, temp;
	cout<<"How many elements you want to insert:";
	cin>>n;
	
	int arr[n];
	
	for(int i=0; i<n; i++){
		cout<<"Enter element "<<i+1<<":";
		cin>>arr[i];
	}
	
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1-i; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	cout<<endl<<endl<<"Sorted list is:"<<endl;
	for(int i=0; i<n; i++){
		cout<<arr[i]<<"\t";
	}
}
