// Firend Circle
// https://leetcode.com/problems/friend-circles/
// https://www.youtube.com/watch?v=1XuCGYE56T0

// ********************************* Disjoint Set Union *********************************

class Solution {
public:
    
    int parent[10001];
    int siz[10001];
    
    void init(){
        
        for(int i=0;i<10001;i++){
            parent[i] = i;
            siz[i] = 1;
        }
    }
    
    int root(int a){
        
        while(a != parent[a])
            a = parent[a];
        
        return a;
    } 
    
    void unionn(int a, int b){
        
        a = root(a);
        b = root(b);
        
        if(a != b){
            if(siz[b] > siz[a])
                swap(a,b);
            parent[b] = a;
            siz[a] += siz[b];
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        
        init();
        
        for(int i=0;i<M.size();i++){
            for(int j=0;j<M[i].size();j++){
                if(M[i][j] == 1)
                    unionn(i+1,j+1);
            }
        }
        
        int cp = 0;
        
        for(int i=1;i<=M.size();i++){
            if(i == parent[i])
                cp++;
        }
        return cp;
    }
};



// ************************************** DFS *******************************************

class Solution {
public:
    
    int vis[10001];
    
    void dfs(int x, vector<vector<int>> &M){
        
        vis[x] = 1;
        
        for(int i=0;i<M[x].size();i++){
            if(!vis[i] and M[x][i] == 1){
                dfs(i,M);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        
        int co = 0;
        
        for(int i=0;i<M[0].size();i++){
            if(!vis[i]){
                co++;
                dfs(i,M);
            }
        }
        return co;
    }
};