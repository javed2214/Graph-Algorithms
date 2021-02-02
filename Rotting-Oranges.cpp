// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        int flag = 0;
        queue <pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    flag = 1;
                    q.push({i, j});
                }
                if(grid[i][j] == 1) flag = 1;
            }
        }
        
        if(flag == 0) return 0;
            
        int res = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        while(!q.empty()){
            int siz = q.size();
            for(int i = 0; i < siz; i++){
                pair <int, int> temp = q.front();
                q.pop();
                for(int j = 0; j < 4; j++){
                    int x = temp.first + dx[j];
                    int y = temp.second + dy[j];
                    if(x >= 0 and y >= 0 and x < n and y < m and grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
            res += 1;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        
        return res-1;
    }
};