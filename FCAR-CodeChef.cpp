/*---------------------------
    Author : Javed Ansari
    Date   : 1 July 2019    
-----------------------------*/

// FCAR CodeChef
// https://www.codechef.com/problems/INSQ15_F

#include<bits/stdc++.h>
#include<cstring>
#include<stdio.h>
using namespace std;
#define MOD1 1000000007
#define MOD2 1000000009
#define rep(i,n) for(i=0;i<n;i++)
#define DB(x) cout<<#x<<"="<<x<<"\n";
#define DB2(x,y) cout<<#x<<"="<<x<<"  "<<#y<<"="<<y<<"\n";
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
#define sc1(x) scanf("%lld",&x)
#define sc2(x,y) scanf("%lld %lld",&x,&y);
#define sc3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z);
#define sc4(x,y,z,p) scanf("%lld %lld %lld %lld",&x,&y,&z,&p);
#define pr(n) printf("%lld\n",n)
#define UNIQUEA(a,n) unique(a,a+n)-a
#define UNIQUEV(v) v.erase(unique(v.begin(),v.end()),v.end())
#define FIND(str,word,startIndex) str.find(word,startIndex)
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
#define umsi unordered_map<string,long long int> 
#define umii unordered_map<long long int,long long int>
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

vector <pair<ll,ll>> g[400*(1<<10)];
vector <ll> v(MX);
ll vis[400*(1<<10)];
ll h[400*(1<<10)],c[400*(1<<10)];

ll dijkstraAlgo(ll u, ll dest){

	typedef pair<ll,ll> P;
	priority_queue<P,vector<P>,greater<P>> pq;

	ll dis[400*(1<<10)];

	for(int i=0;i<(400*(1<<10));i++){
		dis[i]=1e18;
		vis[i]=0;
	}

	dis[u]=0;
	pq.push({0,u});

	while(!pq.empty()){

		ll temp=pq.top().second;
		pq.pop();

		if(vis[temp]) continue;
		vis[temp]=1;

		for(auto it:g[temp]){

			ll v=it.first;
			ll w=it.second;

			if(dis[v] > dis[temp] + w){

				dis[v] = dis[temp] + w;
				pq.push({dis[v],v});
			}
		}
	}
	if(dis[dest]==1e18) return -1; 
	else return dis[dest];
}

void solveQues(){

	ll n,r;
	cin>>n>>r;

	for(int i=1;i<=n;i++) cin>>h[i];
	for(int i=1;i<=n;i++) cin>>c[i];

	for(int i=1;i<=n;i++){
		g[i].pb({n+i,c[i]});
		g[n+i].pb({i,c[i]});
	}

	while(r--){

		ll u,v;
		cin>>u>>v;

		if(h[u]<=h[v]){
			g[u].pb({v,0});
			g[n+v].pb({n+u,0});
		}
		if(h[u]>=h[v]){
			g[n+u].pb({n+v,0});
			g[v].pb({u,0});
		}
	}

	g[0].pb({1,c[1]});
	g[0].pb({n+1,c[1]});

	g[n].pb({2*n+1,0});
	g[2*n].pb({2*n+1,0});

	cout<<dijkstraAlgo(0,2*n+1);
	
	return;
}


int main(){

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	
	solveQues();

	return 0;
}