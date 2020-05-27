// DFS on a Grid
// Program to Check If there is any Path from Top Left Block to Bottom Right Block
// You can Move Only in Either of the Four Directions (Top, Bottom, Left, Right)

#include<bits/stdc++.h>
using namespace std;

int r, c;
int vis[101][101] = {0};

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool isValid(vector <vector<int>> &mat, int tx, int rx){
    return (tx >= 0 and tx < r and rx >= 0 and rx < c and mat[tx][rx] and !vis[tx][rx]);
} 

void dfs(vector<vector<int>> &mat, int u, int v){

    vis[u][v] = 1;

    for(int i = 0; i < 4; i++){
        int tx = u + dx[i];
        int rx = v + dy[i];
        if(isValid(mat, tx, rx))
            dfs(mat, tx, rx);
    }
}

int main(){

    cin >> r >> c;
    vector <vector<int>> mat(r, vector<int> (c));

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> mat[i][j];

    dfs(mat, 0, 0);

    if(vis[r-1][c-1]) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}