// Fire Escape Routes (CodeChef)
// https://www.codechef.com/problems/FIRESC

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MX 100005

vector <ll> g[MX];
int vis[MX];
ll siz=0;

void clearGraph(){

	for(ll i=0;i<MX;i++)
		g[i].clear();

	return;
}

void dfs(ll u){

	if(vis[u]) return;
	siz++;
	vis[u]=1;
	for(auto it:g[u])
		dfs(it);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll test;
	cin>>test;

	while(test--){

		ll n,e;
		cin>>n>>e;

		for(ll i=1;i<=e;i++){

			ll u,v;
			cin>>u>>v;

			g[u].push_back(v);
			g[v].push_back(u);
		}

		memset(vis,0,sizeof(vis));

		ll s=1,count=0;
		for(ll i=1;i<=n;i++){
			if(!vis[i]){
				dfs(i);
				count++;
				s = (s % MOD * siz % MOD) % MOD;
				siz=0;
			}
		}
		cout<<count<<" "<<s<<"\n";

		clearGraph();
	}
	return 0;
}