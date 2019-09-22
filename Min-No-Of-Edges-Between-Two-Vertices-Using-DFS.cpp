// Program to Find Minimum no of Edges Between Two Vertices using DFS
// https://www.geeksforgeeks.org/minimum-number-of-edges-between-two-vertices-of-a-graph-using-dfs/
// Shortest Path Between Two Vertices using DFS

#include<bits/stdc++.h>
using namespace std;
#define MX 101

vector <int> g[MX];
int vis[MX];

void minEdgeDFS(int src, int dest, int &min_cnt, int &cnt){

	vis[src] = 1;

	if(src == dest) min_cnt = min(min_cnt, cnt);

	else{
		for(auto it:g[src]){
			if(!vis[it]){
				cnt++;
				minEdgeDFS(it,dest,min_cnt,cnt);
			}
		}
	}

	vis[src] = 0;		// BackTracking
	cnt--;
}

int main(){

	int n,e;
	cin>>n>>e;

	for(int i=0;i<e;i++){
		
		int u,v;
		cin>>u>>v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	int u,v;
	cin>>u>>v;

	int cnt = 0;
	int min_cnt = INT_MAX;

	minEdgeDFS(u,v,min_cnt,cnt);

	cout<<"Minimum No of Edges Between "<<u<<" and "<<v<<": "<<min_cnt;

	return 0;
}
