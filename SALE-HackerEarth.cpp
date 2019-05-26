// SALE (HackerEarth)
// https://www.hackerearth.com/problem/algorithm/sale-2/

#include<bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, std::vector<int> *AdjList){

	AdjList[u].push_back(v);
	AdjList[v].push_back(u);
}

void DFS(int u, std::vector<int> *AdjList, bool *visited){

	visited[u]=true;
	for(auto it:AdjList[u]){
		if(visited[it]==false){
			DFS(it,AdjList,visited);
		}
	}
}

int main(){

	int test;
	cin>>test;

	while(test--){

		std::vector<int> AdjList[100001];
		bool visited[100001];
		memset(visited,false,sizeof(visited));

		int n,m;
		cin>>n>>m;

		while(m--){

			int u,v;
			cin>>u>>v;

			addEdge(u,v,AdjList);
		}

		int flag=0;

		for(int i=1;i<=n;i++){

			if(AdjList[i].size() > 2){
				flag=1;
				break;
			}
		}

		for(int i=1;i<=n;i++){
			if(AdjList[i].size()<2)
				DFS(i,AdjList,visited);
		}

		for(int i=1;i<=n;i++){
			if(!visited[i])
				flag=1;
		}

		if(flag) cout<<"NO\n";
		else cout<<"YES\n";
	}
}