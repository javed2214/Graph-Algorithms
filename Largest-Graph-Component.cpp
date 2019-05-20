// Program to Find No of Nodes in Largest Graph Components
// Using DFS Traversal

#include<bits/stdc++.h>
using namespace std;
#define MAX 100

vector<int> AdjList[MAX];
bool visited[MAX];
int cnt=0;

void addEdge(int u, int v){

	AdjList[u].push_back(v);
	AdjList[v].push_back(u);
}

void init(int n){

	for(int i=1;i<=n;i++)
		visited[i]=false;
}


void DFS(int u){

	visited[u]=true;

	for(auto it:AdjList[u]){
		if(visited[it]==false){
			cnt++;
			DFS(it);
		}
	}
}

int main(){

	int V=11;

	addEdge(1,2);
	addEdge(2,3);
	addEdge(3,6);
	addEdge(3,7);
	addEdge(1,4);
	addEdge(4,5);
	addEdge(8,9);
	addEdge(8,10);

	init(V);
	int mx=INT_MIN,index;

	for(int i=1;i<=V;i++){
		if(visited[i]==false)
			DFS(i);
		if(cnt > mx){
			mx=cnt;
			index=i;
			cnt=0;
		}
	}
	cout<<mx+1<<" Nodes";
	cout<<endl;

	init(V);
	DFS(index);
	for(int i=1;i<=V;i++){
		if(visited[i]==true)
			cout<<i<<" ";
	}


	return 0;
}
