// Number of Islands Problem
// Application of Connected Components of Graph
// https://www.geeksforgeeks.org/find-number-of-islands/
// TC -> O (ROW * COL)

#include<bits/stdc++.h>
using namespace std;
#define ROW 5
#define COL 5

bool isSafe(int MAT[][COL], int row, int col, bool visited[][COL]){

	return (row >=0 and row < ROW and col >=0 and col < COL and MAT[row][col]==1 and visited[row][col]==false);
}

void DFS(int MAT[][COL], int row, int col, bool visited[][COL]){

	static int rowNbr[]={-1,-1,-1,0,0,1,1,1};
	static int colNbr[]={-1,0,1,-1,1,-1,0,1};

	visited[row][col]=true;

	for(int i=0;i<8;i++){
		if(isSafe(MAT, row + rowNbr[i], col + colNbr[i], visited))
			DFS(MAT, row + rowNbr[i], col + colNbr[i], visited);
	}
}

int countIslands(int MAT[][COL]){

	bool visited[ROW][COL];
	memset(visited,false,sizeof(visited));

	int count=0;

	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			if(visited[i][j]==false and MAT[i][j]==1){
				DFS(MAT,i,j,visited);
				count++;
			}
		}
	}
	return count;
}

int main(){

	int MAT[][COL]={
		{1,1,0,0,0},
		{0,1,0,0,1},
		{1,0,0,1,1},
		{0,0,0,0,0},
		{1,0,1,0,1}
	};

	cout<<"Number of Islands: "<<countIslands(MAT);

	return 0;
}
