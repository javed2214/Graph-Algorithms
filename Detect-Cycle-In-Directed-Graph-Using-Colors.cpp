// Program to Detect Cycle in a Directed Graph Using Colors
// https://www.geeksforgeeks.org/detect-cycle-direct-graph-using-colors/
// https://www.youtube.com/watch?v=AK7BuT5MgU0

// vis[u] = -1 : Unvisited
// vis[u] = 0  : Node is into the Stack (Processed)
// vis[u] = 1  : Visited

#include<bits/stdc++.h>
using namespace std;
#define MX 101

vector <int> g[MX];
int vis[MX];

bool dfs(int u){

	vis[u] = 0;			// Processed

	for(auto it:g[u]){

		if(vis[it] == 0)
			return true;

		if(vis[it] == -1 and dfs(it))
			return true;
	}

	vis[u] = 1;			// Visited

	return false;
}

bool isCyclic(int n){

	for(int i=0;i<MX;i++) vis[i] = -1;		// Unvisited

	for(int i=1;i<=n;i++){
		if(vis[i] == -1){
			if(dfs(i) == true)
				return true;
		}
	}
	return false;
}

int main(){

	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}

	bool x = isCyclic(n);

	if(x) cout<<"Yes";
	else cout<<"No";

	return 0;
}