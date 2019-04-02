#include<iostream>
#include<vector>
#include<map>
using namespace std;

int gcd(int a, int b){
	int r1, r2, r, q;
	if(a > b){
		r1 = a;
		r2 = b;
	}

	else{
		r1 = b;
		r2 = a;
	}

	while(r2 > 0){
		q = r1 / r2;
		r = r1 - (q * r2);
		r1 = r2;
		r2 = r;
	}

	return r1;
}

int maxPoints(vector<pair<int, int> > &points){
	int n;
	n = points.size();

	if(n < 2)
		return n;

	int maxpoints;
	maxpoints = 0;

	map<pair<int, int>, int> slope;

	for(int i=0; i<n-1; i++){
		int verticalPoints, overlapPoints, currmax;
		verticalPoints = 0;
		overlapPoints = 0;
		currmax = 0;

		for(int j=i+1; j<n; j++){
			if(points[i].first == points[j].first && points[i].second == points[j].second)
				overlapPoints++;

			else if(points[i].first == points[j].first)
				verticalPoints++;

			else{
				int xdiff, ydiff, g;
				xdiff = points[j].first - points[i].first;
				ydiff = points[j].second - points[i].second;
				g = gcd(xdiff, ydiff);

				xdiff /= g;
				ydiff /= g;

				slope[make_pair(xdiff, ydiff)]++;

				currmax = max(currmax, slope[make_pair(xdiff, ydiff)]);
			}

			currmax = max(currmax, verticalPoints);
		}

		maxpoints = max(maxpoints, currmax + overlapPoints + 1);
		slope.clear();
	}

	return maxpoints;
}

int main(){
	int n;
	cin>>n;

	vector<pair<int, int> > points;
	for(int i=0; i<n; i++){
		int x, y;
		cin>>x;
		cin>>y;

		points.push_back(make_pair(x, y));
	}

	int result;
	result = maxPoints(points);

	cout<<result;
}
