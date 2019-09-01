// Program to Find Sum of Minimum Elements in All the Connected Components of a Graph
// Using DFS

#include<bits/stdc++.h>
using namespace std;
#define MX 101

vector <int> g[MX];
int vis[MX];

int mi = INT_MAX;

void dfs(int u){

	vis[u] = 1;

	mi = min(mi, u);

	for(auto it:g[u]){
		if(!vis[it]){
			dfs(it);
		}
	}
}

int main(){

	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int sum = 0;

	for(int i=1;i<=n;i++){
		if(!vis[i]){
			mi = INT_MAX;
			dfs(i);
			sum += mi;
		}
	}
	cout<<sum;

	return 0;
}