// BADGE (Codeforces)
// https://codeforces.com/problemset/problem/1020/B

#include<bits/stdc++.h>
using namespace std;

vector<int> AdjList[1001];
bool visited[1001];
std::vector<int> vec;

void addEdge(int u, int v){
	AdjList[u].push_back(v);
}

void DFS(int u){

	visited[u]=true;

	for(auto it:AdjList[u]){
		if(visited[it]==false)
			DFS(it);
		else vec.push_back(it);
	}
}

int main(){

	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
		addEdge(i+1,a[i]);
	memset(visited,false,sizeof(visited));
	for(int i=1;i<=n;i++){
		if(visited[i]==false)
			DFS(i);
		memset(visited,false,sizeof(visited));
	}
	for(auto it:vec) cout<<it<<" ";

	return 0;
}