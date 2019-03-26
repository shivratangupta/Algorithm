#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

bool check(string s1, string s2){
	int count = 0;

	for(int i=0; i<s1.size(); i++){
		if(s1[i] != s2[i])
			count++;

		if(count > 1)
			return false;
	}

	if(count == 1)
		return true;

	else
		return false;
}

int ladderLength(string beginWord, string endWord, vector<string> &wordList){
	vector<int> visited(wordList.size());
	vector<int> arr(wordList.size());

	queue<pair<string, int> > q1;
	queue<pair<string, int> > q2;
	q1.push(make_pair(beginWord, 1));
	q2.push(make_pair(endWord, 0));

	bool flag = true;
	for(int i=0; i<wordList.size(); i++){
		if(wordList[i] == endWord){
			flag = false;
			visited[i] = -1;
			break;
		}
	}

	if(flag)
		return 0;

	while(!q1.empty() || !q2.empty()){
		if(!q1.empty()){
			pair<string, int> p1;
			p1 = q1.front();
			q1.pop();

			for(int i=0; i<wordList.size(); i++){
				if(check(p1.first, wordList[i])){
					if(visited[i] == -1)
						return arr[i] + p1.second + 1;

					else if(visited[i] == 0){
						visited[i] = 1;
						q1.push(make_pair(wordList[i], p1.second + 1));
						arr[i] = p1.second + 1;
					}
				}
			}
		}

		if(!q2.empty()){
			pair<string, int> p2;
			p2 = q2.front();
			q2.pop();

			for(int i=0; i<wordList.size(); i++){
				if(check(p2.first, wordList[i])){
					if(visited[i] == 1)
						return arr[i] + p2.second + 1;

					else if(visited[i] == 0){
						visited[i] = -1;
						q2.push(make_pair(wordList[i], p2.second + 1));
						arr[i] = p2.second + 1;
					}
				}
			}
		}
	}

	return 0;
}

int main(){
	string beginWord, endWord;
	cin>>beginWord;
	cin>>endWord;

	int n;
	cin>>n;

	vector<string> wordList;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		wordList.push_back(s);
	}

	int result;
	result = ladderLength(beginWord, endWord, wordList);

	cout<<result;
}
