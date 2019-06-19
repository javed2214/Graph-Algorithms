// Grid (HackerEarth)
// https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/robot-in-grid-b7d391f7/description/

#include<bits/stdc++.h>
using namespace std;
#define MX 1005

int si,sj,n,p,q,m;
char mat[MX][MX];
int dis[MX][MX];

int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};

void shortestPath(){

	--si;--sj;

	queue<pair<int,int>> q;
	q.push({si,sj});

	memset(dis,-1,sizeof(dis));

	dis[si][sj]=0;

	while(!q.empty()){

		pair<int,int> temp=q.front();
		q.pop();

		int row=temp.first;
		int col=temp.second;

		for(int i=0;i<4;i++){

			int xp=row+dx[i];
			int yp=col+dy[i];

			if(xp<0 || yp<0 || xp>=n || yp>=m) continue;
			if(mat[xp][yp]=='*' || dis[xp][yp]!=-1) continue;
			dis[xp][yp]=dis[row][col]+1;
			q.push({xp,yp});
		}
	}
}

int main(){

	cin>>n>>m>>q;
	
	for(int i=0;i<n;i++)
		cin>>mat[i];

	cin>>si>>sj;
	shortestPath();

	int di,dj;

	for(int i=1;i<=q;i++){
		cin>>di>>dj;
		--di;--dj;
		cout<<dis[di][dj]<<"\n";
	}
	return 0;
}