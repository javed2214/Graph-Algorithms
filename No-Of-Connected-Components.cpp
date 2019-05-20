// Program to Find Number of Connected Components in Graph using DFS
// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/

#include<bits/stdc++.h>
using namespace std;

vector<int> AdjList[1001];
bool visited[1001];

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

	int V=6;

	addEdge(1,2);
	addEdge(2,3);
	addEdge(1,3);
	addEdge(4,5);

	int c=0;
	memset(visited,false,sizeof(visited));

	for(int i=1;i<=V;i++){
		if(visited[i]==false){
			DFS(i);
			c++;
		}
	}
	cout<<"No of Connected Components: "<<c;

	return 0;
}