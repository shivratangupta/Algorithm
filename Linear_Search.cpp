#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number of element in the array:";
	cin>>n;
	
	vector<int> data(n);
	
	cout<<"Enter the element of the array:";
	for(int i=0;i<n;i++){
		cin>>data[i];
	}
	
	int item;
	cout<<"Enter the item which you want to search:";
	cin>>item;
	int loc=0;
	
	for(int i=0;i<n;i++){
		if(data[i]==item)
			loc=i+1;
	}
	
	cout<<endl<<endl;
	if(loc==0)
		cout<<"Item is not in the Data array";
		
	else
		cout<<"Item is in the Data array";
}
