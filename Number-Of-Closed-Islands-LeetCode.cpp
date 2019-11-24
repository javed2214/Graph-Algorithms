// Number of Closed Islands - LeetCode
// https://leetcode.com/problems/number-of-closed-islands/
// https://leetcode.com/problems/number-of-closed-islands/discuss/425150/JavaC%2B%2B-with-picture-Number-of-Enclaves     [Best Explanation]

class Solution {
public:
    
    int dxy[5] = {0, -1, 0, 1, 0};
    
    void fill(vector<vector<int>> &grid, int i, int j, int n, int m){
        
        if(i < 0 or j < 0 or i >= n or j >= m or grid[i][j] == 1) return;
        
        grid[i][j] = 1;
        
        for(int t=0;t<4;t++)
            fill(grid, i + dxy[t], j + dxy[t + 1], n, m);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int res = 0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(i == 0 or j == 0 or i == (n - 1) or j == (m - 1))
                    fill(grid, i, j, n, m);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    res++;
                    fill(grid, i, j, n, m);
                }
            }
        }
        return res;
    }
};