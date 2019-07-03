// Shortest Path in a Matrix using BFS
// 1 -> Path is Open
// 0 -> Path is Closed
// Up | Down | Left | Right

#include<bits/stdc++.h>
using namespace std;

int vis[4][4];

struct node{
	
	int x;
	int y;
	int dis;
};

int findShortestPath(int mat[][4], int p, int q, int n, int m){

	node source;

	source.x=p;
	source.y=q;
	source.dis=0;

	queue<node> pq;

	pq.push(source);
	vis[source.x][source.y]=1;

	while(!pq.empty()){

		node temp=pq.front(),a;
		pq.pop();

		if(temp.x==3 and temp.y==3)
			return temp.dis;

		int fam=temp.x;
		int cam=temp.y;
		int d=temp.dis;

		if(fam-1>=0 and !vis[fam-1][cam] and mat[fam-1][cam]){
			a.x=fam-1;
			a.y=cam;
			a.dis=d+1;
			vis[a.x][a.y]=1;
			pq.push(a);
		}
		if(fam+1<n and !vis[fam+1][cam] and mat[fam+1][cam]){
			a.x=fam+1;
			a.y=cam;
			a.dis=d+1;
			vis[a.x][a.y]=1;
			pq.push(a);
		}
		if(cam-1>=0 and !vis[fam][cam-1] and mat[fam][cam-1]){
			a.x=fam;
			a.y=cam-1;
			a.dis=d+1;
			vis[fam][cam-1]=1;
			pq.push(a);
		}
		if(cam+1<n and !vis[fam][cam+1] and mat[fam][cam+1]){
			a.x=fam;
			a.y=cam+1;
			a.dis=d+1;
			vis[fam][cam+1]=1;
			pq.push(a);
		}
	}
	return -1;
}

int main(){

	int mat[4][4]={
		
		{1,0,1,0},
		{1,1,0,1},
		{0,1,1,0},
		{1,1,1,1}
	};

	cout<<findShortestPath(mat,0,0,4,4);

	return 0;
}