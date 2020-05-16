// Dijkstra Algorithm
// Single Source Shortest Path Algorithm
// https://www.youtube.com/watch?v=CLnpzCnSDSY&list=PL2q4fbVm1Ik64I3VqbVGRfl_OgYzvzt9m&index=7

#include<bits/stdc++.h>
using namespace std;

#define MAX 10001
#define INF INT_MAX
#define P pair<int, int>

vector <pair<int, int>> g[MAX];
vector <int> dis(MAX, INF);

void dijkstraAlgorithm(int root, int n){

    priority_queue <P, vector<P>, greater<P>> pq;
    pq.push({0, root});     // First: Current Distance, Second: Current Node
    dis[1] = 0;

    while(!pq.empty()){

        pair <int, int> temp = pq.top();

        int cur_dis = temp.first;
        int cur_node = temp.second;
        
        pq.pop();

        for(auto it: g[cur_node]){

            if(cur_dis + it.second < dis[it.first]){

                dis[it.first] = cur_dis + it.second;
                pq.push({dis[it.first], it.first});
            }
        }
    }

    for(int i=1;i<=n;i++) cout << dis[i] << " ";

    return;
}

int main(){

    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++){

        int u, v, w;
        cin >> u >> v >> w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijkstraAlgorithm(1, n);    // Shortest Distance from Node 1 to All the Nodes

    return 0;
}
