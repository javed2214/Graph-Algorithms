// Program to Check Whether the Graph is Bipartite or Not using BFS
// https://leetcode.com/problems/is-graph-bipartite/

#include<bits/stdc++.h>
using namespace std;
#define MX 101

vector <int> g[MX];
int color[MX];

bool bfs(int u){

	queue <int> q;
	q.push(u);

	color[u] = 1;

	while(!q.empty()){

		int temp = q.front();
		q.pop();

		for(auto it:g[temp]){
			if(color[it] == -1){
				color[it] = 1 - color[temp];	// Assinging Alternate Color to its Children
				q.push(it);
			}
			else if(color[it] == color[temp])
				return false;
		}
	}
	return true;
}

int main(){

	int n,e;
	cin>>n>>e;

	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	for(int i=0;i<MX;i++) color[i] = -1;

	for(int i=0;i<n;i++){
		if(color[i] == -1){
			if(!bfs(i)){
				cout<<"No";
				return 0;
			}
		}
	}
	cout<<"Yes";

	return 0;
}