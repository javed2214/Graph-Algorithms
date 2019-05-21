// Program to Check if a Graph is Tree or Not
// An Undirected Graph is Tree if it has Following Properties
// => There is No Cycle
// => The Graph is Connected

#include<bits/stdc++.h>
using namespace std;

vector<int> AdjList[101];
bool visited[101];
int parent[101];

void addEdge(int u, int v){

	AdjList[u].push_back(v);
	AdjList[v].push_back(u);
}

bool istreeUtil(int u, bool *visited, int *parent){

	visited[u]=true;
	for(auto it:AdjList[u]){
		if(visited[it]==false){
			parent[it]=u;
			if(istreeUtil(it,visited,parent))
				return true;
		}
		else if(parent[u]!=it)	// Condition for Cycle Detection
			return true;
	}
	return false;
}

bool isTree(int n){

	memset(visited,false,sizeof(visited));
	memset(parent,-1,sizeof(parent));

	if(istreeUtil(0,visited,parent)) return false;

	for(int i=0;i<n;i++)	// Check is Each vertex is Recheable from Root Node
		if(visited[i]==false)
			return false;

	return true;
}

int main(){

	int n=5;

	addEdge(1,0);
	addEdge(0,2);
	addEdge(0,3);
	addEdge(3,4);

	if(isTree(n)) cout<<"Graph is Tree";
	else cout<<"Graph is Not Tree";

	return 0;
}
