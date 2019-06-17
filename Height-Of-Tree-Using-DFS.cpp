// Program to Find Height of a Tree Using DFS

#include<bits/stdc++.h>
using namespace std;
#define MAX 101

vector<int> g[MAX];
bool vis[MAX];

void dfs(int u, int count, int &mx){

	vis[u]=true;
	count+=1;
	for(auto it:g[u]){
		if(vis[it]==false){
			mx=max(mx,count);
			dfs(it,count,mx);
		}
	}
}

int main(){

	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	memset(vis,false,sizeof(vis));
	
	int count=1;
	int mx=-1;

	dfs(1,count,mx);

	cout<<mx;

	return 0;
}