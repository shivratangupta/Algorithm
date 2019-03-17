#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
	if(n == 0)
		return;

	if(m == 0){
		nums1 = nums2;
		return;
	}

	int i;
	i = m;

	for(int j=0; j<n; j++){
		nums1[i] = nums2[j];
		i++;
	}

	sort(nums1.begin(), nums1.end());
}

int main(){
	int m, n;
	cin>>m;
	cin>>n;

	vector<int> nums1(m + n);
	vector<int> nums2(n);

	for(int i=0; i<m; i++){
		int num;
		cin>>num;
		nums1[i] = num;
	}

	for(int i=0; i<n; i++){
		int num;
		cin>>num;
		nums2[i] = num;
	}

	merge(nums1, m, nums2, n);

	for(int i=0; i<m+n; i++)
		cout<<nums1[i]<<"\t";
}
