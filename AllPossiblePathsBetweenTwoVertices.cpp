// All Possible Paths between Two Vertices

#include<bits/stdc++.h>
using namespace std;
#define MX 1001

vector <int> g[MX];

int notVisisted(int x, vector <int> &path){

	for(auto it:path){
		if(x == it) return 0;
	}
	return 1;
}

void printPath(vector <int> &path){

	for(auto it:path)
		cout<<it<<" ";

	cout<<endl;
}

void findPaths(int u, int v){

	queue <vector<int>> q;
	vector <int> path;

	path.push_back(u);
	q.push(path);

	while(!q.empty()){

		path = q.front();
		q.pop();

		int last = path[path.size() - 1];

		if(last == v) printPath(path);

		for(auto it:g[last]){
			if(notVisisted(it, path)){
				vector <int> newPath(path);
				newPath.push_back(it);
				q.push(newPath);
			}
		}
	}
}

int main(){

	int n, m;
	n = 4;
	m = 6;

	int u[] = {1,1,1,2,3,3};
	int v[] = {4,2,3,4,1,2};

	for(int i=0;i<m;i++)
		g[u[i]].push_back(v[i]);	// Directed Graph

	int src, dest;
	cin>>src>>dest;

	findPaths(src, dest);
	
	return 0;
}
