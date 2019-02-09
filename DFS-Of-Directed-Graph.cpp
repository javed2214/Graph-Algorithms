// Program to Find DFS Traversal of Directed Graph

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>&AdjList, int u, int v){
	AdjList[u].push_back(v);
}

void printGraph(vector<vector<int>>&AdjList, int V){
	for(int i=0;i<V;i++){
		cout<<i<<"=>";
		for(auto it:AdjList[i])
			cout<<it<<" ";
		cout<<"\n";
	}
	return;
}

void DFSTraversal(vector<vector<int>>&AdjList, int root, bool *visited){
	visited[root]=true;
	cout<<root<<" ";
	for(auto it:AdjList[root]){
		if(visited[it]==false)
			DFSTraversal(AdjList,it,visited);
	}
}

void DFSUtil(vector<vector<int>>&AdjList ,int root, int V){
	bool *visited=new bool[V+1];
	memset(visited,false,sizeof(visited));

	DFSTraversal(AdjList,root,visited);
}

int main(){

	int V=7;
	vector<vector<int>>AdjList(V);

	addEdge(AdjList,0,1);
	addEdge(AdjList,1,3);
	addEdge(AdjList,4,1);
	addEdge(AdjList,0,2);
	addEdge(AdjList,5,2);
	addEdge(AdjList,6,4);
	addEdge(AdjList,5,6);
	addEdge(AdjList,6,0);

	printGraph(AdjList,V);

	cout<<"\nDFS: ";
	DFSUtil(AdjList,5,V);

	return 0;
}