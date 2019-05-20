// Bishu and His Girlfriends (Hackerearth)
// Graph Problem
// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/

#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

vector<int> AdjList[MAX];
bool visited[MAX];
int dis[MAX];

void addEdge(int u, int v){

	AdjList[u].push_back(v);
	AdjList[v].push_back(u);
}

void BFS(int u){

	queue <int> q;
	q.push(u);

	while(!q.empty()){
		int temp=q.front();
		q.pop();
		for(auto it:AdjList[temp]){
			if(visited[it]==false){
				visited[it]=true;
				dis[it]=dis[temp]+1;
				q.push(it);
			}
		}
	}
}

int main(){

	int n;
	cin>>n;

	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		addEdge(u,v);
	}
	int q,y;
	cin>>q;
	map<int,int> Map;
	set<int> S;
	memset(visited,false,sizeof(visited));
	memset(dis,0,sizeof(dis));
	BFS(1);
	int mi=INT_MAX,ind;
	for(int i=0;i<q;i++){
		int x;
		cin>>x;
		if(dis[x]==mi and x<ind){
			mi=dis[x];
			ind=x;
		}
		if(dis[x]<mi){
			mi=dis[x];
			ind=x;
		}
	}
	cout<<ind;

	return 0;
}