// Find Level of Each Node Using DFS

#include<bits/stdc++.h>
using namespace std;
#define MAX 10001

vector <int> g[MAX];
vector <int> vis(MAX, 0);
vector <int> level(MAX, 0);

void dfs(int u){

    vis[u] = 1;
    for(auto it: g[u]){
        if(!vis[it]){
            level[it] = level[u] + 1;
            dfs(it);
        }
    }
}

int main(){

    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++){

        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    for(int i=1;i<=n;i++) cout << "Level[" << i << "]: " << level[i] << "\n";

    return 0;
}