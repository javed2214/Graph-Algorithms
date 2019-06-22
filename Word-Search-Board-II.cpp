// Word Search Board - II (LeetCode)
// https://leetcode.com/problems/word-search/

bool vis[1001][1001];
int go[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};

bool findWord(int i, int j, int n, int m, int index, vector<vector<char>> &v, string str){

	if(index == str.length()) return true;
	vis[i][j]=true;
    for(int p=0;p<4;p++){
        int nx=i+go[p][0];
        int ny=j+go[p][1];
        if(nx<0 or ny<0 or nx>=n or ny>=m or vis[nx][ny]==true) continue;
            if(v[nx][ny]==str[index]){
                if(findWord(nx,ny,n,m,index+1,v,str))   
                    return true;
                vis[nx][ny]=false;
        }
    }
    return false;
}

class Solution{
	public:
		bool exist(vector<vector<char>> &v, string str){

		if(str.length()==0) return false;
		if(v.size()==0) return false;
            
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++)
                vis[i][j]=false;
        }

		int n=v.size();
		int m=v[0].size();

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(v[i][j]==str[0]){
					bool temp=findWord(i,j,n,m,1,v,str);
					if(temp) return true;
                    vis[i][j]=false;
				}
			}
		}
		return false;
	}
};