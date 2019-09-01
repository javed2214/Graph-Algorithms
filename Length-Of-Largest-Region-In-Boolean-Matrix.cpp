// Program to Find the Length of Largest Region in a Boolean Matrix
// https://www.geeksforgeeks.org/find-length-largest-region-boolean-matrix/

#include<bits/stdc++.h>
using namespace std;
#define MX 101
#define ROW 4 
#define COL 5

int vis[MX][MX];

int rowNmbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int colNmbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isSafe(int M[][COL], int x, int y){

	if(x >= 0 and y >= 0 and x < ROW and y < COL and M[x][y] and !vis[x][y])
		return true;
	return false;
}

void dfs(int M[][COL], int x, int y, int &co){

	vis[x][y] = 1;

	for(int i=0;i<8;i++){
		if(isSafe(M, x + rowNmbr[i], y + colNmbr[i])){
			co++;
			dfs(M, x + rowNmbr[i], y + colNmbr[i], co);
		}
	}
}

int largestRegion(int M[][COL]){

	int mx = INT_MIN;

	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			if(M[i][j] and !vis[i][j]){
				int co = 1;
				dfs(M,i,j,co);
				mx = max(mx, co);
			}
		}
	}
	return mx;
}

int main(){

	int M[][COL] = { {0, 0, 1, 1, 0}, 
                     {1, 0, 1, 1, 0}, 
                     {0, 1, 0, 0, 0}, 
                     {0, 0, 0, 0, 1}
                 	}; 
  
    cout << largestRegion(M);

    return 0;
}