// Chef and Reversing
// https://www.codechef.com/problems/REVERSE
// https://discuss.codechef.com/t/reverse-editorial/6725

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 100005

vector<pair<ll,ll>> g[MX];
ll vis[MX];
ll dis[MX];

ll bfs(ll u, ll dest){

	deque<ll> q;
	for(int i=0;i<MX;i++) dis[i]=INT_MAX, vis[i]=0;

	dis[1]=0;
	q.push_front(1);

	while(!q.empty()){

		ll temp=q.front();
		q.pop_front();
		
		if(vis[temp]) continue;
		vis[temp]=1;
		
		for(auto it:g[temp]){

			ll v=it.first;
			ll w=it.second;

			if(dis[v] > dis[temp]+w){
				dis[v]=dis[temp]+w;
				if(w==1) q.push_back(v);
				else q.push_front(v);
			}
		}
	}
	return dis[dest];
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
	ll d=bfs(1,n);

	if(d==INT_MAX) cout<<"-1\n";
	else cout<<d<<"\n";

	return 0;
}