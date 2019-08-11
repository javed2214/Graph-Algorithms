// Dijkstra Algorithm Implementation
// Applicable for Weighted Graph
// Also called Single Source Shortest Path Algorithm
// No Negative Weights

#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define MX 10
typedef pair<int,int> P;

vector<pair<int,int>> g[MX];

void dijkstraAlgo(int u, int n){

	priority_queue<P,vector<P>,greater<P>> q;
	int dis[MX];
	int vis[MX];
	for(int i=1;i<=n;i++) dis[i]=INF, vis[i]=0;

	q.push({0,u});
	dis[u]=0;

	while(!q.empty()){

		int temp=q.top().second;
		q.pop();

		if(vis[temp]) continue;

		vis[temp]=1;

		for(auto it:g[temp]){
			
			int v=it.first;
			int w=it.second;

			if(dis[v] > dis[temp]+w){
				dis[v]=dis[temp]+w;
				q.push({dis[v],v});
			}
		}
	}
	cout<<"Distance from "<<u<<"\n";
	for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
}

int main(){

	int n,e;
	cin>>n>>e;
	for(int i=1;i<=e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dijkstraAlgo(1,n);

	return 0;
}
