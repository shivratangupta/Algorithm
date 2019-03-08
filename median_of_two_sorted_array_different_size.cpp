#include<iostream>
#include<vector>
using namespace std;

double findmedian(vector<int> &nums1, vector<int> &nums2, int m, int n){
	int min_index, max_index, i, j, median;
	min_index = 0;
	max_index = m;

	while(min_index <= max_index){
		i = (min_index + max_index) / 2;
		j = ((m + n + 1) / 2) - i;

		if(i < m && j > 0 && nums2[j-1] > nums1[i])
			min_index = i + 1;

		else if(i > 0 && j < n && nums2[j] < nums1[i-1])
			max_index = i - 1;

		else{
			if(i == 0)
				median = nums2[j-1];

			else if(j == 0)
				median = nums1[i-1];

			else
				median = max(nums1[i-1], nums2[j-1]);

			break;
		}
	}

	if((m + n) % 2 == 1)
		return median;

	if(i == m)
		return (median + nums2[j]) / 2.0;

	if(j == n)
		return (median + nums1[i]) / 2.0;

	return (median + min(nums1[i], nums2[j])) / 2.0;
}

int main(){
	int m, n;
	vector<int> nums1;
	vector<int> nums2;

	cin>>m;
	for(int i=0; i<m; i++){
		int a;
		cin>>a;
		nums1.push_back(a);
	}

	cin>>n;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		nums2.push_back(a);
	}

	double result;

	if(m < n)
		result = findmedian(nums1, nums2, m, n);

	else
		result = findmedian(nums2, nums1, n, m);

	cout<<result;
}
