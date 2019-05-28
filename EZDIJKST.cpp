// EZDIJKST - Easy Dijkstra Problem (SPOJ)
// https://www.spoj.com/problems/EZDIJKST/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTREAD ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main(){

	FASTREAD

	ll test;
	cin>>test;

	while(test--){

		ll n,m;
		cin>>n>>m;
		unordered_map<ll,vector<pair<ll,ll>>> Map;

		while(m--){

			ll u,v,w;
			cin>>u>>v>>w;
			Map[u].push_back(make_pair(v,w));
		}
		ll u,v;
		cin>>u>>v;

		unordered_map<ll,ll> dist;
		for(int i=1;i<=n;i++) dist[i]=INT_MAX;

		dist[u]=0;
		set<pair<ll,ll>> S;
		S.insert(make_pair(dist[u],u));

		int flag=0;

		while(!S.empty()){

			auto p = *(S.begin());
			ll node = p.second;
			ll nodeDist = p.first;

			S.erase(S.begin());

			for(auto it:Map[node]){
				if(nodeDist + it.second < dist[it.first]){
					auto f = S.find(make_pair(dist[it.first],it.first));
					if(f!=S.end()) S.erase(f);
					dist[it.first] = nodeDist + it.second;
					S.insert(make_pair(dist[it.first],it.first));
				}
				if(v==it.first) flag=1;
			}
		}
		if(!flag) cout<<"NO\n";
		else cout<<dist[v]<<"\n";
	}
	return 0;
}