// Strongly Connected Components (SCC)
// https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/tutorial/

#include<bits/stdc++.h>
using namespace std;
#define MX 101
#define ll long long

vector <ll> g[MX];
ll vis[MX];
stack <ll> S;
ll siz=0;										

void clearGraph(){

	for(ll i=0;i<MX;i++)
		g[i].clear();
}

void dfs1(ll u){

	if(vis[u]) return;
	vis[u]=1;
	for(auto it:g[u])
		dfs1(it);
	S.push(u);
}

void dfs(ll u){

	if(vis[u]) return;
	vis[u]=1;
	siz++;
	for(auto it:g[u])
		dfs(it);
}

int main(){

	ll n,e;
	cin>>n>>e;

	ll u[n+1],v[n+1];

	for(ll i=1;i<=e;i++){
		
		cin>>u[i]>>v[i];
		g[u[i]].push_back(v[i]);
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i])
			dfs1(i);
	}
	memset(vis,0,sizeof(vis));
	clearGraph();

	for(ll i=1;i<=e;i++)
		g[v[i]].push_back(u[i]);

	ll odd=0,even=0,cv=0;

	while(!S.empty()){
		ll u=S.top();
		S.pop();
		if(vis[u]) continue;
		else{
			dfs(u);
			if(siz&1) odd+=siz;
			else even+=siz;
		}
		siz=0;
	}
	cout<<odd-even;

	return 0;
}