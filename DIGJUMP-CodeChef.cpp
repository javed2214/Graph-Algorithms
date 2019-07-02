/*---------------------------
    Author : Javed Ansari
    Date   : 1 July 2019    
-----------------------------*/

// DIGJUMP CodeChef
// https://www.codechef.com/problems/DIGJUMP

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

vector <ll> g[MX];
vector <ll> v(MX);
int vis[MX];
char ch[MX];
string str;
int dis[MX];
unordered_map<int,int> Map;

ll bfs(int src, int n){

	queue<int> q;
	
	for(int i=0;i<n;i++){
		dis[i]=0;
		vis[i]=0;
	}
	q.push(0);
	vis[0]=1;
	dis[0]=0;

	while(!q.empty()){

		int temp=q.front();
		q.pop();

		if(temp==n-1) break;

		if(temp+1<n and vis[temp+1]==0){	// Visit Right Index
			vis[temp+1]=1;
			dis[temp+1]=dis[temp]+1;
			q.push(temp+1);
		}
		
		if(temp-1>=0 and vis[temp-1]==0){	// Visit Left Index
			vis[temp-1]=1;
			dis[temp-1]=dis[temp]+1;
			q.push(temp-1);
		}

		int x=str[temp]-'0';

		if(Map.count(x)==0){	// Visit All its Child Nodes

			Map[x]=1;
		
			for(auto it:g[x]){
				if(vis[it]==0){
					vis[it]=1;
					dis[it]=dis[temp]+1;
					q.push(it);
				}
			}
		}

		if(temp==n-1) break;
	}
	return dis[n-1];
}

void solveQues(){

	cin>>str;

	int n=str.size();
	for(int i=0;i<n;i++)
		g[str[i]-'0'].pb(i);

	cout<<bfs(0,n);
	
	return;
}


int main(){

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	
	solveQues();

	return 0;
}