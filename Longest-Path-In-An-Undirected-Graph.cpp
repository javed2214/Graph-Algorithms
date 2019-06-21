// Program to Find Longest Path in an Undirected Graph/Tree
// ALGORITHM :- https://www.geeksforgeeks.org/longest-path-undirected-tree/
// 2 BFS Algo

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 100005

ll cnt=0;

vector<ll> g[MX];
int vis[MX];
int dis[MX];

int bfs(ll u, ll n){

	queue<ll> q;
	q.push(u);
	vis[u]=1;

	memset(dis,0,sizeof(dis));

	while(!q.empty()){
		ll temp=q.front();
		q.pop();
		for(auto it:g[temp]){
			if(!vis[it]){
				vis[it]=1;
				dis[it]=dis[temp]+1;
				q.push(it);
			}
		}
	}
	ll node,mx=-1;
	for(int i=1;i<=n;i++){
		if(dis[i]>mx){
			mx=dis[i];
			node=i;
		}
	}
	return node;
}

int main(){

	ll n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		ll u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(vis,0,sizeof(vis));

	ll node=bfs(1,n);

	memset(vis,0,sizeof(vis));

	ll xnode=bfs(node,n);

	cout<<dis[xnode];

	return 0;
}