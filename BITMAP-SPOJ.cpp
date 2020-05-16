// BITMAP - SPOJ
// Multisource BFS Application
// https://www.spoj.com/problems/BITMAP/

#include<bits/stdc++.h>
using namespace std;

int a[200][200];
vector <pair<int, int>> v;
int vis[200][200];
int dis[200][200];

bool isValid(int x, int y, int n, int m){
    return (x >= 0 and x < n and y >= 0 and y < m and !vis[x][y]);
}

void init(int n, int m){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            vis[i][j] = 0;
            dis[i][j] = 0;
            a[i][j] = 0;
        }
    }
    v.clear();
}

void bfs(int n, int m){

    queue <pair <int, int>> q;

    for(auto it: v){
        q.push({it.first, it.second});
        vis[it.first][it.second] = 1;
    }

    while(!q.empty()){

        pair <int, int> temp = q.front();
        q.pop();

        static int row[] = {1, -1, 0, 0};
        static int col[] = {0, 0, 1, -1};

        for(int i = 0; i < 4; i ++){

            int x = temp.first + row[i];
            int y = temp.second + col[i];

            if(isValid(x, y, n, m)){
                vis[x][y] = 1;
                q.push({x, y});
                dis[x][y] = dis[temp.first][temp.second] + 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << dis[i][j] <<  " ";
        }
        cout << endl;
    }

    return;
}

int main(){

    int test;
    cin >> test;

    while(test--){

        int n, m;
        cin >> n >> m;

        init(n, m);

        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < s.length(); j++){
                a[i][j] = s[j] - '0';
                if(a[i][j]) v.push_back({i, j});
            }
        }
        bfs(n, m);
    }
    return 0;
}