#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// int a;
// a = rand() % s.size();
// *(s.begin + a);

struct Node{
	int val;
	vector<Node*> neighbors;
};

Node* cloneGraph(Node* node){
	map<Node*, Node*> m;
	queue<Node*> q;
	q.push(node);

	Node* temp = new Node();
	temp->val = node->val;

	m[node] = temp;

	while(!q.empty()){
		Node* temp1;
		temp1 = q.front();
		q.pop();

		vector<Node*> arr;
		arr = temp1->neighbors;

		for(int i=0; i<arr.size(); i++){
			if(m.find(arr[i]) == m.end()){
				Node* temp2 = new Node();
				temp2->val = arr[i]->val;
				m[arr[i]] = temp2;
				q.push(arr[i]);
			}
			m[temp1]->neighbors.push_back(m[arr[i]]);
		}
	}

	return m[node];
}