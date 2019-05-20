// Happy Vertices (Hackerearth)
// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/happy-vertices/

#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

vector<int> AdjList[MAX];
bool visited[MAX];
int parent[MAX];
int child[MAX];

void addEdge(int u, int v){

	AdjList[u].push_back(v);
	AdjList[v].push_back(u);
}

void DFS(int u){

	visited[u]=true;
	
	for(auto it:AdjList[u]){
		if(visited[it]==false){
			parent[it]=u;
			child[u]++;
			DFS(it);
		}
	}
}

void init(int n){
	
	for(int i=1;i<=n;i++){
		visited[i]=false;
		parent[i]=-1;
		child[i]=0;
	}
}

int main(){

	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		addEdge(u,v);
	}
	init(n);

	for(int i=1;i<=n;i++){
		if(visited[i]==false){
			DFS(i);
		}
	}
	int cnt=0;

	for(int i=1;i<=n;i++){
		if(parent[i]!=-1 and child[i] > child[parent[i]])
			cnt++;
	}
	cout<<cnt;

	return 0;
}
