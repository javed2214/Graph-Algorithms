// Program to Find BFS Traversal of Disconnected Graph
// https://www.geeksforgeeks.org/bfs-disconnected-graph/

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

void BFSUtil(vector<vector<int>>&AdjList, bool *visited, int root){

	visited[root]=true;
	queue<int>q;
	q.push(root);
	while(!q.empty()){
		int temp=q.front();
		cout<<temp<<" ";
		q.pop();
		for(auto it:AdjList[temp]){
			if(visited[it]==false){
				visited[it]=true;
				q.push(it);
			}
		}
	}
	return;
}

void BFSTraversal(vector<vector<int>>&AdjList, int V){

	bool *visited=new bool[V];
	memset(visited,false,sizeof(visited));

	for(int i=0;i<V;i++){
		if(visited[i]==false)
			BFSUtil(AdjList,visited,i);
	}
	return;
}

int main(){

	int V=4;
	vector<vector<int>>AdjList(V);

	addEdge(AdjList,0,2);
	addEdge(AdjList,2,0);
	addEdge(AdjList,0,1);
	addEdge(AdjList,2,3);
	addEdge(AdjList,3,3);

	printGraph(AdjList,V);
	cout<<"\n";

	BFSTraversal(AdjList,V);


	return 0;
}