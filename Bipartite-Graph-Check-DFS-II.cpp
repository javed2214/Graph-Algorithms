// Program to Check if Graph is Bipartite or Not using DFS
// https://www.techiedelight.com/determine-given-graph-bipartite-graph-using-dfs/

#include<bits/stdc++.h>
using namespace std;
#define MX 101

vector <int> g[MX];
int vis[MX];
int color[MX];

bool dfs(int u){

	for(auto it:g[u]){
		if(!vis[it]){
			vis[it] = 1;
			color[it] =! color[u];
			if(!dfs(it))
				return false;
		}
		else if(color[it] == color[u])
			return false;
	}
	return true;
}

int main(){

	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0;i<MX;i++) color[i] = -1;

	if(dfs(1)) cout<<"Bipartite Graph!";
	else cout<<"Not a Bipartite Graph!";

	return 0;
}