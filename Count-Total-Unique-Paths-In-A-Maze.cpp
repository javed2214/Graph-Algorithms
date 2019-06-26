// Program to Count Total Unique Paths in a Maze
// Using DFS
// 1 -> Open Cell
// 0 -> Closed Cell
// https://www.techiedelight.com/find-total-number-unique-paths-maze-source-destination/

#include<bits/stdc++.h>
using namespace std;

#define N 4
#define M 4

int vis[N][N];

void countPaths(int maze[][4], int i, int j, int &cnt){

	if(i<0 or j<0 or i>=N or j>=M or !maze[i][j] or vis[i][j]) return;

	if(i == N-1 and j == M-1){
		cnt++;
		return;
	}

	vis[i][j]=1;

	countPaths(maze,i+1,j,cnt);
	countPaths(maze,i-1,j,cnt);
	countPaths(maze,i,j+1,cnt);
	countPaths(maze,i,j-1,cnt);

	vis[i][j]=0;
}

int main(){

	int maze[N][M]={
		{1, 1, 1, 1},
		{1, 1, 0, 1},
		{0, 1, 0, 1},
		{1, 1, 1, 1}
	};

	int cnt=0;
	memset(vis,0,sizeof(vis));

	countPaths(maze,0,0,cnt);

	cout<<cnt;

	return 0;
}
