// Program to Find Number of Nodes at Specific Level in a Graph using BFS

#include<bits/stdc++.h>
using namespace std;
#define MX 101

vector <int> g[MX];
int vis[MX];
int level[MX];

int bfs(int u, int n, int lev){

	queue <int> q;
	q.push(u);

	vis[u] = 1;

	while(!q.empty()){

		int temp = q.front();
		q.pop();

		for(auto it:g[temp]){
			if(!vis[it]){
				vis[it] = 1;
				q.push(it);
				level[it] = level[temp] + 1;
			}
		}
	}

	int cnt = 0;

	for(int i=1;i<=n;i++)
		if(level[i] == lev)
			cnt++;

	return cnt;
}

int main(){

	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int lev;
	cout << "Enter Level: ";
	cin >> lev;

	cout << bfs(1,n,lev-1);

	return 0;
}