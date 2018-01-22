#include<iostream>
#include<conio.h>
using namespace std;

int main(){

	int arr[10], Loc=0, max;

	for(int i=0; i<10; i++){
		cout<<endl<<"Enter the Element "<<i+1<<":";
		cin>>arr[i];	
	}

	max = arr[0];

	for(int i=0; i<10; i++){
		if(max < arr[i]){
			max = arr[i];
			Loc = i;
		}
	}

	cout<<"Maximum Number in the array is:"<<max<<endl;
	cout<<"Position of the array is:"<<Loc+1;
}
