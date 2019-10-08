// Program to Count No of Ways to Reach Destination Using BFS
// https://www.geeksforgeeks.org/count-number-of-ways-to-reach-destination-in-a-maze-using-bfs/

// You can Move Either Right or Bottom
// 0 -> Blockage
// 1 -> Free

#include<bits/stdc++.h>
using namespace std;
#define R 3
#define C 4

int countPaths(int mat[R][C]){

	queue <pair<int,int>> q;
	q.push({0,0});

	int cnt = 0;

	while(!q.empty()){

		pair <int,int> temp = q.front();
		q.pop();

		if(temp.first == R - 1 and temp.second == C - 1) cnt++;

		if(temp.first + 1 < R and mat[temp.first + 1][temp.second] == 1) q.push({temp.first + 1, temp.second});
		if(temp.second + 1 < C and mat[temp.first][temp.second + 1] == 1) q.push({temp.first, temp.second + 1});
	}

	return cnt;
}

int main(){

	int mat[R][C] = {
		{1,0,0,1},
		{1,1,1,1},
		{1,0,1,1}
	};

	cout << countPaths(mat);
}