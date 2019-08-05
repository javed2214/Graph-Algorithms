// Program to Check Whether the Graph is Bipartite or Not using DFS
// https://leetcode.com/problems/is-graph-bipartite/

#include<bits/stdc++.h>
using namespace std;
#define MX 101

vector <int> g[MX];
int color[MX];

bool dfs(int u){

	for(auto it:g[u]){
		if(color[it] == -1){
			color[it] = !color[u];
			if(!dfs(it))
				return false;
		}
		else if(color[it] == color[u])
			return false;
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
			if(!dfs(i)){
				cout<<"No";
				return 0;
			}
		}
	}
	cout<<"Yes";

	return 0;
}