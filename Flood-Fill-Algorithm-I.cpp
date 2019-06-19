// Check if there is Path from Source to Destination
// Using Flood Fill Algorithm
// '1' : Represents there is no Blockage
// '0' : Represents there is Blockage
// Can either move Left, Right, Top and Bottom

#include<bits/stdc++.h>
using namespace std;
#define MAX 10

char mat[4][4]={
		
		{'S','0','1','0'},
		{'1','1','1','0'},
		{'0','1','1','1'},
		{'1','0','0','D'}
	};

bool vis[MAX][MAX];

void dfs(int sx, int sy, int dx, int dy){

	if(sx>=4 or sy>=4 or sx<0 or sy<0 or mat[sx][sy]=='0' or vis[sx][sy]) return;
	
	vis[sx][sy]=true;

	dfs(sx-1,sy,dx,dy);
	dfs(sx+1,sy,dx,dy);
	dfs(sx,sy-1,dx,dy);
	dfs(sx,sy+1,dx,dy);
}

int main(){

	memset(vis,false,sizeof(vis));
	dfs(0,0,3,3);
	if(vis[3][3]) cout<<"POSSIBLE";
	else cout<<"IMPOSSIBLE";


	return 0;
}