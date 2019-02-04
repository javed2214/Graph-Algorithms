// All Possible Paths between Two Vertices

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &AdjList, int u, int v){

	AdjList[u].push_back(v);
	AdjList[v].push_back(u);
}
void printGraph(vector<vector<int>> &AdjList, int V){

	cout<<"\n";
	for(int i=0;i<V;i++){
		cout<<i<<"=>";
		for(auto it:AdjList[i])
			cout<<it<<" ";
		cout<<"\n";
	}
}
int notVisited(vector<int>&path, int it){

	for(auto ptr:path){
		if(ptr==it)
			return 0;
	}
	return 1;
}
void printPaths(vector<int> &path){

	for(auto it:path)
		cout<<it<<"->";
	cout<<"\n";
}
void findPaths(vector<vector<int>> &AdjList, int src, int dst, int V){

	queue <vector<int>> q;
	vector <int> path;
	path.push_back(src);
	q.push(path);
	while(!q.empty()){
		path=q.front();
		q.pop();
		int last=path[path.size()-1];
		
		if(last==dst) printPaths(path);

		for(auto it:AdjList[last]){
			if(notVisited(path,it)){
				vector<int> newPath(path);
				newPath.push_back(it);
				q.push(newPath);
			}
		}
	}
}

int main(){

	int V=9;
	vector<vector<int>> AdjList(V);

	addEdge(AdjList,0,1);	
	addEdge(AdjList,0,2);
	addEdge(AdjList,0,3);
	addEdge(AdjList,1,4);
	addEdge(AdjList,2,4);
	addEdge(AdjList,2,5);
	addEdge(AdjList,3,6);
	addEdge(AdjList,5,7);
	addEdge(AdjList,7,6);
	addEdge(AdjList,6,8);
	addEdge(AdjList,7,8);
	
	printGraph(AdjList,V);

	cout<<"\n";
	int u,v;
	cin>>u>>v;
	cout<<"\n";
	findPaths(AdjList,u,v,V);

	return 0;
}