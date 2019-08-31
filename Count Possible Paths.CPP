// Program to Count Number of Possible Paths between Two Vertices
// [ Directed Graph ]
// Backtracking Application

#include<bits/stdc++.h>
using namespace std;
#define MX 101

vector <int> g[MX];
int vis[MX];
int co = 0;

void countPath(int src, int dest){

	vis[src] = 1;

	if(src == dest)
		co++;
	
	else{
		for(auto it:g[src]){
			if(!vis[it])
				countPath(it,dest);
		}
	}
	vis[src] = 0;
}

int main(){

	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}

	int src, dest;
	cin>>src>>dest;

	countPath(src, dest);

	cout<<"No of Possible Paths: "<<co;

	return 0;
}

/*

Test Case:

3 3
1 2
2 3
1 3
1 3

Output:

No of Possible Paths: 2

*/
