// Unreachable Nodes
// Program to Find Number of Nodes which are Unreachable from Head Nodes
// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1001

vector<int> AdjList[MAX];
bool visited[MAX];

void addEdge(int u, int v){

	AdjList[u].push_back(v);
	AdjList[v].push_back(u);
}

void DFS(int u){

	visited[u]=true;
	for(auto it:AdjList[u]){
		if(visited[it]==false)
			DFS(it);
	}
}

int main(){

	int n,m,u,v;
	// n -> No of Nodes
	// m -> No of Edges
 	cin>>n>>m;

	for(int i=0;i<m;i++){
		cin>>u>>v;
		addEdge(u,v);
	}
	int head;
	cin>>head;

	memset(visited,false,sizeof(visited));
	DFS(head);
	ll c=0;
	for(int i=1;i<=n;i++){
		if(visited[i]==false)
			c++;
	}
	cout<<c;
	cout<<endl;

	return 0;
}
