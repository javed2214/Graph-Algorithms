// Cycle Detection in Directed Graph using DFS
// https://www.youtube.com/watch?v=AK7BuT5MgU0
// Using Coloring Method

// -1 : Node is Unvisited
//  0 : Node is Present in the Stack
//  1 : Node is Visited

#include<bits/stdc++.h>
using namespace std;
#define MX 101

vector<int> g[MX];
int vis[MX];

bool detectCycle(int u){

	if(vis[u]==0) return true;
	if(vis[u]==1) return false;

	vis[u]=0;

	for(auto it:g[u]){
		if(detectCycle(it))
			return true;
	} 
	vis[u]=1;

	return false;
}

int main(){

	int n,e;
	cin>>n>>e;

	for(int i=1;i<=e;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}

	for(int i=0;i<MX;i++) vis[i]=-1;

	for(int i=1;i<=n;i++){
		if(vis[i]==-1 and detectCycle(i)){
			cout<<"Contains Cycle!";
			return 0;
		}
	}
	cout<<"Graph is Acyclic!";

	return 0;
}