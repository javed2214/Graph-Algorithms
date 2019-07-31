// Program to Print Cycle in an Undirected Graph
// Using DFS

#include<bits/stdc++.h>
using namespace std;
#define MX 101

vector<int> g[MX];
int vis[MX];
int parent[MX];

int fam,cam;

bool dfs(int u, int par){

	vis[u] = 1;	

	for(auto it:g[u]){
		if(!vis[it]){
			parent[it] = u;
			if(dfs(it,u))
				return true;
		}
		else if(it != par){
			fam = it;
			cam = u;
			return true;
		}
	}
	return false;
}

int main(){

	int n, m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	bool x = dfs(1,-1);

	if(x){
		cout<<"Cycle is Present\n";
	
		while(true){
			cout<<cam<<" ";
			cam = parent[cam];
			if(cam == fam) break;
		}
		cout<<cam;
	}
	else cout<<"Not Present!";

	return 0;
}
