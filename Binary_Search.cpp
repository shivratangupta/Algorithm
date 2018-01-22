#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int arr[10], beg, end, mid, item;
	
	cout<<"Enter the element of the array"<<endl;
	for(int i=0; i<10; i++){
		cout<<"Enter the element "<<i+1<<":";
		cin>>arr[i];
	}
	
	cout<<endl<<"Enter the item which you want to search:";
	cin>>item;
	
	beg=0;
	end=10;
	
	mid = (beg+end)/2;
	
	while(arr[mid] != item){
		if(item < arr[mid]){
			end = mid-1;
		}
		
		else{
			beg = mid+1;
		}
		
		mid = (beg+end)/2;
	}
	
	if(arr[mid] == item){
		cout<<"Item is found in the array";
	}
	
	else{
		cout<<"Item is not found in the array";
	}
}
