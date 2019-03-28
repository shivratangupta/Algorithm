#include<iostream>
#include<vector>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
	int n, start, end, petrol;
	n = gas.size();
	start = 0;
	end = 1;

	petrol = gas[start] - cost[start];

	if(n == 1 && petrol >= 0)
		return start;

	while(end != start || petrol < 0){
		while(end != start && petrol < 0){
			petrol -= gas[start] - cost[start];
			start = (start + 1) % n;

			if(start == 0)
				return -1;
		}

		petrol += gas[end] - cost[end];
		end = (end + 1) % n;
	}

	return start;
}

int main(){
	int n;
	cin>>n;

	vector<int> gas;
	vector<int> cost;

	for(int i=0; i<n; i++){
		int g, c;
		cin>>g;
		cin>>c;
		gas.push_back(g);
		cost.push_back(c);
	}

	int result;
	result = canCompleteCircuit(gas, cost);

	cout<<result;
}
