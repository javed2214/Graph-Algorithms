// Flood Fill
// https://leetcode.com/problems/flood-fill/


// ============================================ DFS ============================================

class Solution {
public:
    
    int n,m;
    
    void flood(vector<vector<int>>& image, int sr, int sc, int newColor, int co){
        
        if(sr < 0 or sc < 0 or sr >= n or sc >= m or image[sr][sc] != co or image[sr][sc] == newColor)
            return;
        
        image[sr][sc] = newColor;
        
        flood(image,sr-1,sc,newColor,co);
        flood(image,sr,sc-1,newColor,co);
        flood(image,sr+1,sc,newColor,co);
        flood(image,sr,sc+1,newColor,co);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int co = image[sr][sc];
        
        n = image.size();
        m = image[0].size();
        
        flood(image,sr,sc,newColor,co);
        
        return image;
    }
};



// ============================================ BFS ============================================

class Solution {
public:
    
    int n,m;
    
    bool check(int sr, int sc, int newColor, int co, vector<vector<int>>& image){
        if(sr < 0 or sc < 0 or sr >= n or sc >= m or image[sr][sc] != co or image[sr][sc] == newColor)
            return false;
        return true;
    }
    
    void flood(vector<vector<int>>& image, int sr, int sc, int newColor, int co){
        
        queue <pair<int,int>> q;
        q.push({sr,sc});
        
        image[sr][sc] = newColor;
        
        while(!q.empty()){
            
            pair<int,int> temp = q.front();
            q.pop();
            
            int x = temp.first;
            int y = temp.second;
            
            if(check(x-1,y,newColor,co,image)){
                q.push({x-1,y});
                image[x-1][y] = newColor;
            }
            if(check(x,y-1,newColor,co,image)){
                q.push({x,y-1});
                image[x][y-1] = newColor;
            }
            if(check(x+1,y,newColor,co,image)){
                q.push({x+1,y});
                image[x+1][y] = newColor;
            }
            if(check(x,y+1,newColor,co,image)){
                q.push({x,y+1});
                image[x][y+1] = newColor;
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int co = image[sr][sc];
        
        n = image.size();
        m = image[0].size();
        
        flood(image,sr,sc,newColor,co);
        
        return image;
    }
};