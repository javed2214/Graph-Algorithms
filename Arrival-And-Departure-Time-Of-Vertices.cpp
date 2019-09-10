// Arrival and Departure Time of Vertices in a Graph using DFS
// https://www.techiedelight.com/arrival-departure-time-vertices-dfs/

#include<bits/stdc++.h>
using namespace std;
#define MX 101

vector <int> g[MX];
int vis[MX];
int arrival[MX];
int departure[MX];

void dfs(int u, int &time){

	vis[u] = 1;

	arrival[u] = ++time;

	for(auto it:g[u]){
		if(!vis[it])
			dfs(it,time);
	}
	departure[u] = ++time;
}

int main(){

	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}

	int time = -1;

	for(int i=1;i<=n;i++){
		if(!vis[i])
			dfs(i,time);
	}
	for(int i=1;i<=n;i++){
		cout<<"Vertex: "<<i<<"("<<arrival[i]<<","<<departure[i]<<")";
		cout<<endl;
	}
	return 0;
}