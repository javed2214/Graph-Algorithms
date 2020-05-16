// DIGJUMP CodeChef
// https://www.codechef.com/problems/DIGJUMP

#include<bits/stdc++.h>
using namespace std;
#define MAX 100002

vector <int> g[MAX];
vector <int> vis(MAX, 0);
vector <int> dis(MAX, 0);

int bfs(int root, int n, string &s){

    queue <int> q;
    q.push(root);

    vis[root] = 1;
    dis[root] = 0;

    while(!q.empty()){

        int temp = q.front();
        q.pop();

        if(temp == n - 1) return dis[temp];

        if(temp - 1 >= 0 and !vis[temp - 1]){       // Visiting Left Index
            vis[temp - 1] = 1;
            dis[temp - 1] = dis[temp] + 1;
            q.push(temp - 1);
        }

        if(temp + 1 < n and !vis[temp + 1]){        // Visiting Right Index
            vis[temp + 1] = 1;
            dis[temp + 1] = dis[temp] + 1;
            q.push(temp + 1);
        }

        int val = s[temp] - '0';

        for(auto it: g[val]){                       // Visiting All the Child Nodes
            if(!vis[it]){
                vis[it] = 1;
                dis[it] = dis[temp] + 1;
                q.push(it);
            }
        }

        g[val].clear();
    }
    return -1;
}

int main(){

    string s;
    cin >> s;

    int n = s.length();
    
    for(int i = 0; i < n; i++){
        int x = s[i] - '0';
        g[x].push_back(i);
    }

    cout << bfs(0, n, s);

    return 0;
}

/*

012134444444443
0 0
1 1
2 2
1 3
3 4
4 5
4 6
4 7

*/
