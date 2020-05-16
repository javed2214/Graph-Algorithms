// Find All the Bridges in a Given Graph
// A Bridge is an Edge in a Graph, whose Removal Increases the Number of Components
// Tutorial: https://www.youtube.com/watch?v=ECKTyseo2H8&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=23

#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

vector <int> g[MAX];
vector <int> vis(MAX, 0);
int in[MAX], low[MAX];

int timer = 0;

void dfs(int u, int par){

    vis[u] = 1;
    in[u] = low[u] = timer++;

    for(auto it: g[u]){

        if(it == par) continue;
        
        if(vis[it]){
            // Back Edge
            low[u] = min(low[u], in[it]);
        }

        else{
            // Forward Edge
            dfs(it, u);
            
            if(low[it] > in[u]) cout << u << " - " << it << " is a Bridge\n";

            low[u] = min(low[u], low[it]);
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

    dfs(1, -1);

    return 0;
}

/*

Example:

Input
4 4
1 2
2 3
3 4
4 2

Output
1 - 2 is a Bridge

*/