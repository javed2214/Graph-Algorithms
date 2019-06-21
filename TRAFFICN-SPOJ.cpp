// TRAFFICN - Traffic Network (SPOJ)
// https://www.spoj.com/problems/TRAFFICN/

/*---------------------------
    Author : Javed Ansari
    Date   : 21 June 2019    
-----------------------------*/

#include<bits/stdc++.h>
#include<cstring>
#include<stdio.h>
using namespace std;
#define MOD1 1000000007
#define MOD2 1000000009
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define DB(x) cout<<#x<<"="<<x<<"\n";
#define DB2(x,y) cout<<#x<<"="<<x<<"  "<<#y<<"="<<y<<"\n";
#define FASTREAD ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define SORTV(a) sort(a.begin(),a.end())
#define SORTA(a,n) sort(a,a+n)
#define TEST(t) ll t; cin>>t; while(t--)
#define PI 2*acos(0.0)
#define pb push_back
#define eb emplace_back
#define RFOR(i,n) for(int i=(n)-1;i>=0;i--)
#define endl cout<<"\n";
#define co cout<<
#define SS cout<<"*";	
#define INSERT(index, str) str.insert(index,str)
#define REPLACE(str,start,count,new_str) str.replace(start,count,new_str)
#define COUNT(str,ch) count(str.begin(),str.end(),ch)
#define ERASE(str,index) str.erase(str.begin()+index)
#define MAXA(a,n) *max_element(a,a+n)
#define MINA(a,n) *min_element(a,a+n)
#define REV(v) reverse(v.begin(),v.end())
#define SUM(v) accumulate(v.begin(),v.end(),0)
#define MAXV(v) *max_element(v.begin(),v.end())
#define MINV(v) *min_element(v.begin(),v.end())
#define ull unsigned long long
#define ll long long int
#define ld long double
#define SIZE 100000001
#define INF 0x7fffffff

const int MX = 1e5+5;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int ddx[] = {1,0,-1,0,1,-1,-1,1};
int ddy[] = {0,1,0,-1,1,-1,1,-1};

vector <pair<ll,ll>> g1[MX],g2[MX];
vector <ll> v(MX);
bool vis[MX];

ll dis1[MX],dis2[MX];

typedef pair<ll,ll> P;

void clearGraph(){

	for(int i=0;i<MX;i++){
		g1[i].clear();
		g2[i].clear();
	}
}

ll bfs(ll src, vector<pair<ll,ll>> *g, ll *dis){

	priority_queue<P,vector<P>,greater<P>> q;
	memset(vis,false,sizeof(vis));
	for(int i=0;i<MX;i++) dis[i]=INF;

	q.push({0,src});
	dis[src]=0;

	while(!q.empty()){

		ll temp=q.top().second;
		q.pop();
		if(vis[temp]) continue;
		vis[temp]=true;

		for(auto it:g[temp]){

			ll v=it.first;
			ll w=it.second;

			if(dis[v] > dis[temp] + w){
				dis[v] = dis[temp] + w;
				q.push({dis[v],v});
			}
		}
	}
}

void solveQues(){

	ll test;
	cin>>test;

	while(test--){

		ll n,m,k,s,t;
		cin>>n>>m>>k>>s>>t;

		for(int i=0;i<m;i++){
			ll u,v,w;
			cin>>u>>v>>w;
			g1[u].push_back({v,w});
			g2[v].push_back({u,w});
		}
		bfs(s,g1,dis1);
		bfs(t,g2,dis2);

		ll mi=dis1[t];

		for(int i=0;i<k;i++){
			ll u,v,w,x,tx;
			cin>>u>>v>>w;
			mi=min(mi,min(dis1[u]+w+dis2[v], dis1[v]+w+dis2[u]));
		}
		if(mi==INF) mi=-1;
		cout<<mi<<"\n";
		
		clearGraph();
	}

	return;
}


int main(){

	FASTREAD;
	solveQues();

	return 0;
}