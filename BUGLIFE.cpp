// BUGLIFE - A Bug's Life (SPOJ Problem)
// https://www.spoj.com/problems/BUGLIFE/
// Approach: https://unacademy.com/lesson/buglife-spoj-solution-using-bfs/T8UKF28E

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 100005

vector<ll> g[MX];
ll vis[MX];
ll level[MX];

void clearGraph(ll n){

	for(ll i=1;i<=n;i++){
		g[i].clear();
		vis[i]=0;
		level[i]=0;
	}
}

void bfs(ll u){

	queue<ll> q;
	q.push(u);
	vis[u]=1;

	for(auto it:g[u]){
		if(!vis[it]){
			vis[it]=1;
			level[it]=level[u]+1;
			q.push(it);
		}
	}
}

int main(){

	ll test;
	cin>>test;

	ll cp=1;

	while(test--){

		ll n,m;
		cin>>n>>m;
		ll u[m+1],v[m+1];

		for(int i=1;i<=m;i++){
			
			cin>>u[i]>>v[i];

			g[u[i]].push_back(v[i]);
			g[v[i]].push_back(u[i]);
		}
		
		for(int i=1;i<=n;i++)
			if(!vis[i])
				bfs(i);

		int flag=0;

		for(int i=1;i<=m;i++){
			if(abs(level[u[i]] - level[v[i]]) % 2 == 0){
				flag=1;
				break;
			}
		}
		
		clearGraph(n);

		cout<<"Scenario #"<<cp++<<":\n";
		if(!flag) cout<<"No suspicious bugs found!\n";
		else cout<<"Suspicious bugs found!\n";
	}

	return 0;
}