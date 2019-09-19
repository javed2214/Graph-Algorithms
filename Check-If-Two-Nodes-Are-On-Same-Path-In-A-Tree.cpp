// Program to Check if Two Nodes are on Same Path in a Tree
// https://www.geeksforgeeks.org/check-if-two-nodes-are-on-same-path-in-a-tree/

#include<bits/stdc++.h>
using namespace std;
#define MAX 101

vector <int> g[MAX];
int vis[MAX];
int intime[MAX];
int outtime[MAX];

int timer = 0;

void dfs(int u){

	vis[u] = 1;
	
	intime[u] = ++timer;

	for(auto it:g[u]){
		if(!vis[it])
			dfs(it);
	}

	outtime[u] = ++timer;
}

bool onSamePath(int u, int v){

	if((intime[u] < intime[v] and outtime[u] > outtime[v]) or (intime[v] < intime[u] and outtime[v] > outtime[u])) return true;
	return false;
}

int main(){

	int n;
	cin>>n;

	for(int i=0;i<n-1;i++){
		
		int u,v;
		cin>>u>>v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1);

	int x,y;
	cin>>x>>y;

	if(onSamePath(x,y)) cout<<"Same Path!\n";
	else cout<<"Different Path!\n";

	return 0;
}