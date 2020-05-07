// CONNECT - CodeForces
// https://codeforces.com/problemset/problem/1130/C

#include<bits/stdc++.h>
using namespace std;

void dfs(vector <vector<int>> &mat, int x, int y, int n, vector <pair <int, int>> &v){

	if(x < 0 or x >= n or y < 0 or y >= n or mat[x][y] == 1) return;

	v.push_back({x, y});
	mat[x][y] = 1;
	
	dfs(mat, x + 1, y, n, v);
	dfs(mat, x, y + 1, n, v);
	dfs(mat, x, y - 1, n, v);
	dfs(mat, x - 1, y, n, v);
}

int main(){

    int n;
    cin >> n;

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    r1--; c1--; r2--; c2--;
    string s;

    vector <vector<int>> mat(n, vector<int>(n, 0));
    vector <pair<int, int>> v1, v2;

    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++){
            mat[i][j] = s[j] - '0';
        }
    }

    dfs(mat, r1, c1, n, v1);
    if(mat[r2][c2]) return !printf("0");
    dfs(mat, r2, c2, n, v2);

    int mi = INT_MAX;

    for(auto it: v1){

        int t1 = it.first + 1;
        int t2 = it.second + 1;

        for(auto pt: v2){

            int t3 = pt.first + 1;
            int t4 = pt.second + 1;

            int x = (t1 - t3) * (t1 - t3) + (t2 - t4) * (t2 - t4);
            mi = min(mi, x);
        }
    }

    cout << mi << endl;

    return 0;
}
