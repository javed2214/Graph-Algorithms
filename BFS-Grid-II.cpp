// BFS on Grid
// Shortest Path from Source to Destination

#include<bits/stdc++.h>
using namespace std;
#define MX 101

int dx[]={+1,-1,0,0};
int dy[]={0,0,+1,-1};

int shortestPath(char mat[][4]){

	int n=4,m=4,x=0,y=0;
	int flag=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j]=='S'){
				x=i;
				y=j;
				flag=1;
				break;
			}
		}
		if(flag) break;
	}
	queue<pair<int,int>> q;
	q.push({x,y});

	int dis[n][m];
	memset(dis,-1,sizeof(dis));

	dis[x][y]=0;

	while(!q.empty()){

		pair<int,int> temp=q.front();
		q.pop();

		int row=temp.first;
		int col=temp.second;

		for(int i=0;i<4;i++){

			int xx = row + dx[i];
			int yy = col + dy[i];

			if(xx<0 || yy<0 || xx>=n || yy>=m || mat[xx][yy]=='0' || dis[xx][yy]!=-1) continue;		// dis[][] Matrix can be used as visited[][] Matrix
			dis[xx][yy]=dis[row][col]+1;
			q.push({xx,yy});
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j]=='D')
				return dis[i][j];
		}
	}

	return -1;
}

int main(){

	char mat[4][4]={

		{'S','1','1','1'},		// Shortest Path from S to D
		{'1','0','1','0'},
		{'0','1','1','1'},
		{'1','0','0','D'}
	};

	cout<<shortestPath(mat);

	return 0;
}