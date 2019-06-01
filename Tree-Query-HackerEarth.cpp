// Tree Query Problem (HackerEarth)
// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/tree-query/description/

#include<bits/stdc++.h>
#include<cstring>
#include<stdio.h>
using namespace std;
#define MOD1 1000000007
#define MOD2 1000000009
#define DB(x) cout<<#x<<"="<<x<<"\n";
#define DB2(x,y) cout<<#x<<"="<<x<<"  "<<#y<<"="<<y<<"\n";
#define FASTREAD ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define SORTV(a) sort(a.begin(),a.end())
#define SORTA(a,n) sort(a,a+n)
#define TEST(t) ll t; cin>>t; while(t--)
#define PI 2*acos(0.0)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define RFOR(i,n) for(int i=(n)-1;i>=0;i--)
#define endl cout<<"\n";
#define co cout<<
#define SS cout<<"*";
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
#define MX 2000005

vector<ll> AdjList1[MX];
vector<ll> AdjList2[MX];

void solveQues(){

	ll n,m;
	cin>>n>>m;
	ll a[n+1];
	for(int i=1;i<=m;i++){
		ll u,v;
		cin>>u>>v;
		AdjList1[v].push_back(u);
		AdjList2[v].push_back(u);
	}
	ll c1=0,c2=0;
	for(int i=1;i<=n;i++){
		if(AdjList1[i].size()==0) c1++;
		if(AdjList2[i].size()==0) c2++;
	}
	co max(c1,c2);
}


int main(){

	FASTREAD;
	solveQues();

	return 0;
}
