// Chef and Reversing
// https://www.codechef.com/problems/REVERSE
// https://discuss.codechef.com/t/reverse-editorial/6725

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 100005
typedef pair<ll,ll> P;

vector<pair<ll,ll>> g[MX];
ll vis[MX];
ll dis[MX];

void dijkstraAlgo(ll src, ll dest){

	for(int i=0;i<MX;i++){
		vis[i]=0;
		dis[i]=1e9;
	}
	priority_queue<P,vector<P>,greater<P>> q;
	dis[src]=0;
	q.push({0,src});

	while(!q.empty()){

		ll temp=q.top().second;
		q.pop();

		if(vis[temp]) continue;
		vis[temp]=1;

		for(auto it:g[temp]){

			ll v=it.first;
			ll w=it.second;

			if(dis[v] > dis[temp] + w){
				dis[v] = dis[temp] + w;
				q.push({dis[v],v});
			}
		}
	}
	if(dis[dest]==1e9) cout<<"-1";
	else cout<<dis[dest];
}

int main(){

	ll n,m;
	cin>>n>>m;

	for(ll i=1;i<=m;i++){
		ll u,v;
		cin>>u>>v;
		g[u].push_back({v,0});
		g[v].push_back({u,1});
	}

	dijkstraAlgo(1,n);

	return 0;
}