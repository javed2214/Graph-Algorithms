/*---------------------------
    Author : Javed Ansari
    Date   : 1 July 2019    
-----------------------------*/

// https://www.codechef.com/problems/KQM15A

#include<bits/stdc++.h>
#include<cstring>
#include<stdio.h>
using namespace std;
#define MOD1 1000000007
#define MOD2 1000000009
#define FOR(n) for(int i=0;i<n;i++)
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
#define umii unordered_map<long long int,long long sint>
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
int vis[11][11];

int mat[11][11];

struct node{

	int src;
	int dest;
	int dis;
};

bool isValid(int x, int y, int n, int m){

	if(x<0 or y<0 or x>=n or y>=m) return false;
	return true;
}

int bfs(int x, int y, int n, int m){

	queue <node> q;

	node source;

	source.src=x;
	source.dest=y;
	source.dis=0;

	q.push(source);

	vis[source.src][source.dest]=1;

	while(!q.empty()){

		node temp = q.front(), X;
		q.pop();

		int ps=temp.src;
		int qs=temp.dest;
		int rs=temp.dis;

		if(mat[temp.src][temp.dest]==2)
			return temp.dis;

		if(ps-1>=0 and !vis[ps-1][qs]){
			X.src=ps-1;
			X.dest=qs;
			X.dis=rs+1;
			vis[ps-1][qs]=1;
			q.push(X);
		}
		if(ps+1<n and !vis[ps+1][qs]){
			X.src=ps+1;
			X.dest=qs;
			X.dis=rs+1;
			vis[ps+1][qs]=1;
			q.push(X);
		}
		if(qs-1>=0 and !vis[ps][qs-1]){
			X.src=ps;
			X.dest=qs-1;
			X.dis=rs+1;
			vis[ps][qs-1]=1;
			q.push(X);
		}
		if(qs+1<m and !vis[ps][qs+1]){
			X.src=ps;
			X.dest=qs+1;
			X.dis=rs+1;
			vis[ps][qs+1]=1;
			q.push(X);
		}
	}
	return -1;
}

void solveQues(){

	int n,m;
	cin>>n>>m;

	int x,y;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
			if(mat[i][j]==1){
				x=i;
				y=j;
			}
		}
	}

	cout<<bfs(x,y,n,m);
	
	return;
}


int main(){

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	
	solveQues();

	return 0;
}