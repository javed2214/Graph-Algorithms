// Program to Find Mother Vertex in Directed Graph
// A Mother Vertex is the Vertex from Where we can Visit to Each Node of a Graph
// https://www.geeksforgeeks.org/find-a-mother-vertex-in-a-graph/

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
	for(auto it:AdjList[root]){
		if(visited[it]==false)
			DFSTraversal(AdjList,it,visited);
	}
}

int DFSUtil(vector<vector<int>>&AdjList, int V){
	bool *visited=new bool[V];
	memset(visited,false,sizeof(visited));
	int v=0;
	for(int i=0;i<V;i++){
		if(visited[i]==false){
			DFSTraversal(AdjList,i,visited);
			v=i;
		}
	}
	memset(visited,false,sizeof(visited));
	DFSTraversal(AdjList,v,visited);

	for(int i=0;i<V;i++){
		if(visited[i]==false)
			return -1;
	}
	return v;
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
	
	cout<<"\n";
	int x=DFSUtil(AdjList,V);
	
	if(x==-1) cout<<"No Mother Vertex Exist!";
	else cout<<"Mother Vertex: "<<x;

	return 0;
}