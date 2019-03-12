#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval{
	int start;
	int end;
};

bool comparison(const Interval &a, const Interval &b){
	return a.start < b.start;
}

vector<Interval> merge(vector<Interval> &intervals){
	if(intervals.size() <= 1)
		return intervals;

	sort(intervals.begin(), intervals.end(), comparison);

	for(int i=0; i<intervals.size()-1; i++){
		if(intervals[i].end >= intervals[i+1].start){
			intervals[i].end = max(intervals[i].end, intervals[i+1].end);
			intervals.erase(intervals.begin() + i + 1);
			i--;
		}
	}

	return intervals;
}

int main(){
	int n;
	cin>>n;

	vector<Interval> arr;
	for(int i=0; i<n; i++){
		Interval point;
		cin>>point.start;
		cin>>point.end;
		arr.push_back(point);
	}

	vector<Interval> result;
	result = merge(arr);

	for(int i=0; i<result.size(); i++){
		cout<<result[i].start<<"\t";
		cout<<result[i].end<<endl;
	}
}
