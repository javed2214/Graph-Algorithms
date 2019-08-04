// Island Perimeter
// https://leetcode.com/problems/island-perimeter/
// https://www.youtube.com/watch?v=fFQVHjNUwyU

class Solution {
public:
    
    int Count(vector<vector<int>> &grid, int i, int j){
        
        int co = 0;
        
        if(j-1 < 0 or grid[i][j-1] == 0) co++;
        if(j+1 >= grid[0].size() or grid[i][j+1] == 0) co++;
        if(i-1 < 0 or grid[i-1][j] == 0) co++;
        if(i+1 >= grid.size() or grid[i+1][j] == 0) co++;
        
        return co;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int peri = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]){
                    peri += Count(grid,i,j);
                }
            }
        }
        return peri;
    }
};