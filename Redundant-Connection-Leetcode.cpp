// Redundant Connection LeetCode
// https://leetcode.com/problems/redundant-connection/
// Using Union Find Algorithm

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector <int> parent(2000, 0);
        
        for(int i=0;i<parent.size();i++)
            parent[i] = i;
        
        vector<int> v;
        
        for(auto it:edges){
            
            int n1 = it[0];
            int n2 = it[1];
            
            while(n1 != parent[n1]) n1 = parent[n1];
            while(n2 != parent[n2]) n2 = parent[n2];
            
            if(n1 == n2)
                v = it;
            
            else parent[n2] = n1;
        }
        return v;
    }
};