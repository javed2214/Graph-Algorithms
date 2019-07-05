// Program to Count Number of Shortest Paths Available from Source to All the Nodes in Undirected Weighted Graph
// Source Node - 1
// Modified Dijkstra

#include<bits/stdc++.h>
using namespace std;
#define MX 101
#define inf 1e8

typedef pair<int,int> P;

vector<pair<int,int>> g[MX];
int vis[MX];
int dis[MX];
int cnt[MX];

void dijkstra(int src){

	priority_queue<P,vector<P>,greater<P>> pq;

	for(int i=0;i<MX;i++){
		vis[i]=0;
		dis[i]=inf;
	}

	dis[src]=0;
	pq.push({0,src});

	while(!pq.empty()){

		int temp=pq.top().second;
		pq.pop();

		if(vis[temp]) continue;
		vis[temp]=1;

		for(auto it:g[temp]){

			int v=it.first;
			int w=it.second;

			if(dis[v] > dis[temp] + w){
				cnt[v] = 1;
				dis[v] = dis[temp] + w;
				pq.push({dis[v],v});
			}
			else if(dis[v] == dis[temp] + w)
				cnt[v] += 1;
		}
	}
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

	dijkstra(1);

	cout<<"No of Shortest Paths from Source Node 1: \n"; 

	for(int i=1;i<=n;i++)
		cout<<cnt[i]<<" ";

	return 0;
}