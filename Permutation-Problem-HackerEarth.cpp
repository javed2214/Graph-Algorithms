// Permutation Problem HackerEarth
// Using BFS
// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/t1-1-6064aa64/

#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;
	int a[n],x;
	string source;
	for(int i=0;i<n;i++){
		cin>>x;
		source+=(x+'0');
	}
	string dest=source;
	sort(dest.begin(),dest.end());

	queue<string> q;

	q.push(source);
	map<string,int> Map;
	Map[source]=0;

	while(!q.empty()){
		string s=q.front();
		q.pop();
		if(s==dest){
			cout<<Map[dest]<<endl;
			break;
		}
		for(int i=2;i<=n;i++){
			string p=s;
			reverse(p.begin(),p.begin()+i);
			if(Map.find(p)==Map.end()){
				Map[p]=Map[s]+1;
				q.push(p);
			}
		}
	}

	return 0;
}