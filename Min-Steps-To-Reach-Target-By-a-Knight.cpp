// Minimum Steps to Reach Target by a Knight
// https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/

#include<bits/stdc++.h>
using namespace std;
#define MX 101

int vis[MX][MX];

typedef struct node{
	int x;
	int y;
	int dis;
}node;

int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool isSafe(int x, int y, int n){

	if(x >= 1 and y >= 1 and x <= n and y <= 30) return true;
	return false;
}

int minStepToReachTarget(int srcX, int srcY, int destX, int destY, int N){

	queue <node> q;
	
	node p;
	
	p.x = srcX;
	p.y = srcY;
	p.dis = 0;
	
	q.push(p);

	vis[srcX][srcY] = 1;

	while(!q.empty()){

		node temp = q.front();
		q.pop();

		if(temp.x == destX and temp.y == destY) return temp.dis;

		for(int i=0;i<8;i++){

			int x = temp.x + dx[i];
			int y = temp.y + dy[i];

			if(isSafe(x,y,N) and !vis[x][y]){
				
				vis[x][y] = 1;
				node p;
				p.x = x;
				p.y = y;
				p.dis = temp.dis + 1;
				q.push(p);
			}
		}
	}
	return -1;
}

int main(){

	int N = 30; 
    int srcX = 1, srcY = 1;
    int destX = 30, destY = 30;
    
    cout << minStepToReachTarget(srcX, srcY, destX, destY, N); 

    return 0;
}