/*---------------------------
    Author : Javed Ansari
    Date   : 27 June 2019    
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

vector <ll> g[MX];
vector <ll> v(MX);
bool vis[MX];

ll siz[MX];

void init(ll n){

	for(int i=1;i<MX;i++)
		siz[i]=0;
}

bool check(ll n){

	for(int i=1;i<=n;i++)
		if(siz[i]==1)
			return true;

	return false;
}

void clearGraph(ll n){

	for(int i=1;i<MX;i++)
		g[i].clear();
}

void solveQues(){

	TEST(t){

		ll n,m;
		cin>>n>>m;

		init(n);

		for(int i=1;i<=m;i++){
			ll u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		for(int i=1;i<=n;i++){
			siz[i]=g[i].size();
		}

		ll cp=0;

		while(check(n)){
			for(int i=1;i<=n;i++){
				if(siz[i]==1){
					v.push_back(i);
				}
			}
			for(int j=0;j<v.size();j++){
				if(siz[v[j]]==1){
					siz[v[j]]--;
					ll u=g[v[j]][0];
					g[v[j]].pop_back();
					remove(g[u].begin(),g[u].end(),v[j]);
					siz[u]--;
				}
			}
			v.clear();
			cp++;
		}
		cout<<cp<<"\n";

		clearGraph(n);
	}

	return;
}


int main(){

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	
	solveQues();

	return 0;
}