// Similar String Groups
// https://leetcode.com/problems/similar-string-groups/

class Solution {
public:
    
    vector<int> g[10001];
    int vis[10001];
    
    void dfs(int u){
        
        vis[u] = 1;
        
        for(auto it:g[u]){
            if(!vis[it]){
                dfs(it);
            }
        }
    }
    
    bool check(string s1, string s2){
        
        if(s1.length() != s2.length()) return false;
        if(s1 == s2) return true;
        int co = 0;
        for(int i=0;i<s1.length();i++){
            if(s1[i] != s2[i])
                co++;
        }
        if(co <= 2) return true;
        return false;
    }
    
    void connect(int s1, int s2){
        
        g[s1].push_back(s2);
        g[s2].push_back(s1);
    }
    
    int numSimilarGroups(vector<string>& a) {
        
        for(int i=0;i<a.size();i++)
            vis[i] = 0;
        
        for(int i=0;i<a.size()-1;i++){
            for(int j=i+1;j<a.size();j++){
                if(check(a[i],a[j])){
                    connect(i,j);
                }
            }
        }
        int count = 0;
        for(int i=0;i<a.size();i++){
            if(!vis[i]){
                count++;
                dfs(i);
            }
        }
        return count;
    }
};