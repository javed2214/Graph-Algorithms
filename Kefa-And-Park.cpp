// Kefa and Park (Codeforces)
// https://codeforces.com/contest/580/problem/C

#include<bits/stdc++.h>
#include<cstring>
#include<stdio.h>
using namespace std;
#define MOD1 1000000007
#define MOD2 1000000009
#define DB(x) cout<<#x<<"="<<x<<"\n";
#define DB2(x,y) cout<<#x<<"="<<x<<"  "<<#y<<"="<<y<<"\n";
#define FASTREAD ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define SORT(a) sort(a.begin(),a.end())
#define TEST(t) ll t; cin>>t; while(t--)
#define PI 2*acos(0.0)
#define endl cout<<"\n";
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
#define ll long long int
#define ld long double
#define SIZE 100000001
#define INF 0x7fffffff

vector<int> AdjList[100001];
bool visited[100001];
ll ans=0;

void addEdge(int u, int v){
	
	AdjList[u].push_back(v);
	AdjList[v].push_back(u);
}

void DFS(int u, int cnt, int *a, int m){

	visited[u]=true;
	
	if(a[u]) cnt++;
	else cnt=0;
	if(cnt>m) return;

	for(auto it:AdjList[u]){
		if(visited[it]==false)
			DFS(it,cnt,a,m);
	}
	if(AdjList[u].size()==1 and u!=1)
		ans++;
}

void SOLVE_QUESTION(){	

	int n,m;
	cin>>n>>m;
	int a[n+2];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		addEdge(u,v);
	}
	DFS(1,0,a,m);
	cout<<ans;

	return;
}


int main(void){

	FASTREAD;
	SOLVE_QUESTION();

	return 0;
}