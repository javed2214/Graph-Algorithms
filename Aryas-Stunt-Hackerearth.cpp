// Aray's Stunt HackerEarth
// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/aryas-stunt-63b3da17/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100005

vector<ll> g[MAX];
ll vis[MAX];
ll a[MAX];
vector<ll> v;
vector<vector<ll>> res;

void dfs(ll u){
	vis[u]=1;
	v.push_back(u);
	for(auto it:g[u]){
		if(vis[it]==0)
			dfs(it);
	}
}

int main(){

	ll n,e;
	cin>>n>>e;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=0;i<e;i++){
		ll u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(vis,0,sizeof(vis));
	for(ll i=1;i<=n;i++){
		if(vis[i]==0){
			dfs(i);
			res.push_back(v);
			v.clear();
		}
	}

	std::vector<ll> X;
	ll mx=-1,kill=0,inj=0,sum=0,pp;
	for(ll i=0;i<res.size();i++){
		sum=0;mx=-1;
		for(ll j=0;j<res[i].size();j++){
			if(a[res[i][j]] > mx){
				pp=res[i][j];
				mx=a[res[i][j]];
			}
			sum+=a[res[i][j]];
		}
		kill+=mx;
		inj+=sum-mx;
		X.push_back(pp);
	}
	sort(X.begin(),X.end());
	cout<<kill<<" "<<inj<<"\n";
	for(auto it:X) cout<<it<<" ";
	cout<<"\n";

	return 0;
}