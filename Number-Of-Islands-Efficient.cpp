// Number of Islands Problem
// https://leetcode.com/problems/number-of-islands/
// Time : O(n * m)
// Space : O(1)

class Solution {
public:
    
    void dfs(vector <vector<char>> &grid, int x, int y, int n, int m){
        
        if(x < 0 or x >= n or y < 0 or y >= m or grid[x][y] != '1') return;
        
        grid[x][y] = '0';
        
        dfs(grid, x + 1, y, n, m);
        dfs(grid, x, y + 1, n, m);
        dfs(grid, x - 1, y, n, m);
        dfs(grid, x, y - 1, n, m);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size() == 0) return 0;
        int n = grid.size();
        int m = grid[0].size();
        
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j, n, m);
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};