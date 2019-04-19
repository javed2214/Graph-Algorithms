// BFS on Matrix/Grid
// Shortest Distance Between Two Cells in a Matrix/Grid

#include<bits/stdc++.h>
using namespace std;

#define N 4
#define M 4

typedef struct node{
	int row;
	int col;
	int dist;
}node;

int minDistance(char grid[N][M]){

	node source;
	bool visited[N][M];

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(grid[i][j]=='0')
				visited[i][j]=true;
			else
				visited[i][j]=false;
			if(grid[i][j]=='s'){
				source.row=i;
				source.col=j;
				source.dist=0;
			}
		}
	}
	queue <node> q;
	q.push(source);
	visited[source.row][source.col]=true;

	while(!q.empty()){

		node temp=q.front(),pp;
		q.pop();

		if(grid[temp.row][temp.col]=='d')
			return temp.dist;

		if(temp.row-1>=0 and visited[temp.row-1][temp.col]==false){
			pp.row=temp.row-1;
			pp.col=temp.col;
			pp.dist=temp.dist+1;
			q.push(pp);
			visited[temp.row-1][temp.col]=true;
		}

		if(temp.row+1<N and visited[temp.row+1][temp.col]==false){
			pp.row=temp.row+1;
			pp.col=temp.col;
			pp.dist=temp.dist+1;
			q.push(pp);
			visited[temp.row+1][temp.col]=true;
		}

		if(temp.col-1>=0 and visited[temp.row][temp.col-1]==false){
			pp.row=temp.row;
			pp.col=temp.col-1;
			pp.dist=temp.dist+1;
			q.push(pp);
			visited[temp.row][temp.col-1]=true;
		}

		if(temp.col+1<M and visited[temp.row][temp.col+1]==false){
			pp.row=temp.row;
			pp.col=temp.col+1;
			pp.dist=temp.dist+1;
			q.push(pp);
			visited[temp.row][temp.col+1]=true;
		}
	}
	return -1;
}

int main(){

	char grid[N][M]={
		
		{'0','*','0','s'},	// s-> Source
		{'*','0','*','*'},	// d-> Destination
		{'0','0','*','*'},
		{'d','*','*','*'}
	};

	cout<<minDistance(grid);

	return 0;
}