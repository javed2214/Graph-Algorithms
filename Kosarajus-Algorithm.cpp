// Kosaraju's Algorithm for Strongly Connected Components (SCC) in Directed Graph

// Algorithm Steps:-
// 1. Run DFS and Keep track of Finish Time of Each Node using Stack
// 2. Reverse Each Edges of Graph (Taking Transpose)
// 3. Run DFS According to the Maintained Stack

#include<bits/stdc++.h>
using namespace std;
#define MX 101

vector <int> g[MX];
bool vis[MX];
stack <int> S;

void clearGraph(){

	for(int i=0;i<MX;i++)
		g[i].clear();
}

void dfs(int u){

	if(vis[u]) return;
	vis[u]=true;
	for(auto it:g[u])
		dfs(it);
	S.push(u);
}

int main(){

	int n,e;
	cin>>n>>e;

	int u[n+1],v[n+1];

	for(int i=1;i<=e;i++){
	
		cin>>u[i]>>v[i];
		g[u[i]].push_back(v[i]);
	}
	memset(vis,false,sizeof(vis));

	for(int i=1;i<=n;i++){
		if(!vis[i])
			dfs(i);
	}

	memset(vis,false,sizeof(vis));
	clearGraph();

	for(int i=1;i<=n;i++)
		g[v[i]].push_back(u[i]);

	int c=0;

	while(!S.empty()){

		int u=S.top();
		S.pop();
		if(vis[u]) continue;
		else dfs(u),c++;
	}
	
	cout<<"No of Strongly Connected Components: "<<c;

	return 0;
}