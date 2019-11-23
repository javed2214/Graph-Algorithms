// Longest Increasing Path in a Matrix
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
    
    int n, m;
    vector<vector<int>> dp;
    
    int dx[5] = {0, -1, 0, 1, 0};
    
    int dfs(vector<vector<int>> &mat, int x, int y){
        
        if(dp[x][y] != -1) return dp[x][y];
        
        dp[x][y] = 1;
        
        for(int i=0;i<4;i++){
            
            int tx = x + dx[i];
            int ty = y + dx[i+1];
            
            if(tx < 0 or ty < 0 or tx >= n or ty >= m or mat[tx][ty] <= mat[x][y]) continue;
            
            dp[x][y] = max(dp[x][y], 1 + dfs(mat, tx, ty));
        }
        return dp[x][y];
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        
        if(mat.empty()) return 0;
        
        n = mat.size();
        m = mat[0].size();
        
        dp = vector<vector<int>> (n, vector<int> (m, -1));
        
        int mx = 0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                mx = max(mx, dfs(mat,i,j));
        
        return mx;
    }
};