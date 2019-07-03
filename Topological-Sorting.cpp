// Topological Sorting
// https://www.youtube.com/watch?v=dis_c84ejhQ
// Topological Sort can be Applied to Only DAG (Directed Acyclic Graphs)

#include<bits/stdc++.h>
using namespace std;
#define MX 101

vector<int> g[MX];
int vis[MX];
stack<int> S;

void topoSortUtil(int u){

	vis[u]=1;
	for(auto it:g[u]){
		if(vis[it]==0)
			topoSortUtil(it);
	}
	S.push(u);
}

void topoSort(int n){

	for(int i=1;i<=n;i++)
		if(vis[i]==0)
			topoSortUtil(i);

	while(!S.empty()){
		cout<<S.top()<<" ";
		S.pop();
	}
}

int main(){

	int n,e;
	cin>>n>>e;

	for(int i=1;i<=e;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	topoSort(n);

	return 0;
}