#include<iostream>
using namespace std;

int main(){
	int n, temp;
	cout<<"How many elements you want to insert:";
	cin>>n;
	
	int arr[n], min;
	
	for(int i=0; i<n; i++){
		cout<<"Enter element "<<i+1<<":";
		cin>>arr[i];
	}
	
	for(int i=0; i<n-1; i++){
		min = i;
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
			
		if(min != i){
			temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
	
	cout<<endl<<endl<<"Sorted list is:"<<endl;
	for(int i=0; i<n; i++){
		cout<<arr[i]<<"\t";
	}
}
