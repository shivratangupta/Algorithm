#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

vector<string> fullJustify(vector<string> &words, int maxWidth){
	vector<string> result;
	string s = "";
	int n, count;
	n = 0;
	count = 0;

	for(int i=0; i<words.size(); i++){
		n += words[i].size();
		if(n <= maxWidth){
			n += 1;
			count++;
		}

		else{
			n -= words[i].size();
			n -= count;

			if(count == 1){
				s += words[i - 1];

				for(int j=s.size(); j<maxWidth; j++)
					s += ' ';
			}

			else{
				int totalSpace, space, extraSpace;
				totalSpace = maxWidth - n;
				space = totalSpace / (count - 1);
				extraSpace = totalSpace % (count - 1);

				s += words[i - count];
				for(int j=i-count+1; j<i; j++){
					for(int k=0; k<space; k++)
						s += ' ';

					if(extraSpace > 0){
						s += ' ';
						extraSpace--;
					}

					s += words[j];
				}
			}

			result.push_back(s);
			s = "";
			n = 0;
			count = 0;
			i--;
		}
	}

	for(int i=words.size()-count; i<words.size()-1; i++){
		s += words[i];
		s += ' ';
	}

	s += words[words.size() - 1];

	for(int i=s.size(); i<maxWidth; i++)
		s += ' ';

	result.push_back(s);

	return result;
}

int main(){
	int n, maxWidth;
	cin>>n;

	vector<string> arr;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		arr.push_back(s);
	}

	cin>>maxWidth;

	vector<string> result;
	result = fullJustify(arr, maxWidth);

	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<endl;
}