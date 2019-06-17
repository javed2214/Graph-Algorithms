// Program to Find Number of Ways to Reach from Source Node to Destination Node with Shortest Path Taken
// dis[] Array Stores Level of Node
// ways[] Array Stores No of Ways
 
#include<bits/stdc++.h>
using namespace std;
#define MX 101

vector<int> g[MX];
bool vis[MX];
int ways[MX];
int dis[MX];

void bfs(int u, int v){

	queue<int> q;
	q.push(u);
	vis[u]=true;
	ways[u]=1;

	while(!q.empty()){

		int temp=q.front();
		q.pop();

		for(auto it:g[temp]){
			if(vis[it]==false){
				vis[it]=true;
				ways[it]+=ways[temp];
				dis[it]=dis[temp]+1;
				q.push(it);
			}
			else{
				if(dis[it]==dis[temp]+1)
					ways[it]+=ways[temp];
			}
		}
	}
	cout<<ways[v];

	return;
}

int main(){

	int n,e;
	cout<<"Enter No of Nodes and Edges: ";
	cin>>n>>e;

	memset(vis,false,sizeof(vis));

	for(int i=1;i<=e;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int src,dest;
	src=1;
	dest=4;

	bfs(src,dest);

	return 0;
}