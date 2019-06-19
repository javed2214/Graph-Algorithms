// Protect Sheep (CodeForces)
// https://codeforces.com/problemset/problem/948/A

#include<bits/stdc++.h>
using namespace std;
#define MX 505

bool vis[MX][MX];

void dfs(int sx, int sy, int r, int c, char mat[][MX]){

	if(sx<0 or sy<0 or sx>=r or sy>=c or vis[sx][sy] or mat[sx][sy]=='D') return;

	vis[sx][sy]=true;
	mat[sx][sy]='W';

	dfs(sx-1,sy,r,c,mat);
	dfs(sx,sy-1,r,c,mat);
	dfs(sx+1,sy,r,c,mat);
	dfs(sx,sy+1,r,c,mat);
}

int main(){

	int r,c;
	cin>>r>>c;

	char mat[MX][MX];
	int count=0;

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>mat[i][j];
			if(mat[i][j]=='S') count++;
			if(mat[i][j]=='.')
				mat[i][j]='D';
		}
	}
	memset(vis,false,sizeof(vis));

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(mat[i][j]=='W' and !vis[i][j])
				dfs(i,j,r,c,mat);
		}
	}

	int xtz=0;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			if(mat[i][j]=='S') xtz++;
	}

	if(xtz==count){

		cout<<"Yes\n";

		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				cout<<mat[i][j];
			cout<<"\n";
		}
	}
	else cout<<"No\n";

	return 0;
}