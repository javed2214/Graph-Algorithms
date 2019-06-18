// Program to Print the Cycle Formed by Directed Graph

#include<bits/stdc++.h>
using namespace std;
#define MX 101

vector<int> g[MX];
int vis[MX];
int parent[MX];

int cx;

bool detectCycle(int u){

	cx=u;

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

	std::vector<int> v;

	for(int i=1;i<=e;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		if(i==1) parent[u]=-1;
		parent[v]=u;
	}

	for(int i=0;i<MX;i++) vis[i]=-1;

	for(int i=1;i<=n;i++){
		if(vis[i]==-1 and detectCycle(i)){
			
			int x=cx;
			x=parent[x];
			
			while(x!=cx){
				v.push_back(x);
				x=parent[x];
			}
			v.push_back(x);
			
			reverse(v.begin(),v.end());
			
			for(auto it:v) cout<<it<<" ";

			return 0;
		}
	}
	return 0;
}