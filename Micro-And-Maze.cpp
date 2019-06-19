// Micro and Maze (HackerEarth)
// https://www.hackerearth.com/practice/algorithms/graphs/flood-fill-algorithm/tutorial/

#include<bits/stdc++.h>
using namespace std;

bool vis[11][11];

void dfs(int sx, int sy, int dx, int dy, int n, int m, int a[][11]){

	if(sx<0 or sy<0 or sx>=n or sy>=m or vis[sx][sy] or a[sx][sy]==0) return;

	vis[sx][sy]=true;

	dfs(sx-1,sy,dx,dy,n,m,a);
	dfs(sx+1,sy,dx,dy,n,m,a);
	dfs(sx,sy-1,dx,dy,n,m,a);
	dfs(sx,sy+1,dx,dy,n,m,a);
}

int main(){

	int n,m;
	cin>>n>>m;

	int a[11][11];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];

	memset(vis,false,sizeof(vis));

	dfs(0,0,n-1,m-1,n,m,a);

	if(vis[n-1][m-1]) cout<<"Yes";
	else cout<<"No";

	return 0;
}