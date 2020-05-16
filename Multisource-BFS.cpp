// Multisource Path in Unweighted Graph
// Modified BFS Algorithm
// Most Efficient Approach
// https://www.geeksforgeeks.org/multi-source-shortest-path-in-unweighted-graph/

#include<bits/stdc++.h>
using namespace std;
#define MAX 100002

vector <int> g[MAX];
vector <int> vis(MAX, 0);
vector <int> dis(MAX, 0);

void bfs(vector <int> &source, int n){

    queue <int> q;
    
    for(int i = 0; i < source.size(); i++){
        q.push(source[i]);
        vis[source[i]] = 1;
    }

    while(!q.empty()){

        int temp = q.front();
        q.pop();

        for(auto it: g[temp]){
            if(!vis[it]){
                vis[it] = 1;
                dis[it] = dis[temp] +  1;
                q.push(it);
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << "dis[" << i << "]: " << dis[i] << endl;

    return;
}

int main(){

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){

        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int s;
    cin >> s;

    vector <int> source(s);

    for(int i = 0; i < s; i++) cin >> source[i];

    bfs(source, n);

    return 0;
}