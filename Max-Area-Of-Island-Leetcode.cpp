// Max Area of Island
// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    
    int vis[51][51];
    int mx = 0;
    
    void dfs(int x, int y, int n, int m, vector<vector<int>> &grid, int &count){
        
        if(x < 0 or y < 0 or x >= n or y >= m or !grid[x][y] or vis[x][y])
            return;
        
        ++count;
        mx = max(mx,count);
        vis[x][y] = 1;
        
        dfs(x-1,y,n,m,grid,count);
        dfs(x,y-1,n,m,grid,count);
        dfs(x+1,y,n,m,grid,count);
        dfs(x,y+1,n,m,grid,count);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]){
                    count = 0;
                    dfs(i,j,n,m,grid,count);
                }
            }
        }
        return mx;
    }
};