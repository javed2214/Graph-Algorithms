// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
    
    vector <int> g[100001];
    int vis[100001];
    
    void dfs(int u){
        vis[u] = 1;
        for(auto it: g[u]){
            if(!vis[it])
                dfs(it);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& con) {
        
        int edge = 0;
        
        for(auto it: con){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
            edge += 1;
        }
        
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i);
                cnt += 1;
            }
        }
        
        if(edge < n - 1) return -1;
        return cnt - 1;
    }
};
