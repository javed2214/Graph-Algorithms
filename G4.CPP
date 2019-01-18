// DFS Traversal of Graph (Iterative)

#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list <int> *adjList;
public:
	Graph(int V){
		this->V=V;
		adjList=new list <int> [V];
	}
	void addEdge(int u, int v){		// Directed Graph
		adjList[u].push_back(v);
	}
	void DFS(int root);
	void DFSUtil(int root, bool *visited);
};
void Graph:: DFS(int root){
	bool *visited=new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	DFSUtil(root, visited);
}
void Graph:: DFSUtil(int root, bool *visited){
	stack <int> S;
	S.push(root);
	while(!S.empty()){
		int temp=S.top();
		S.pop();
		if(visited[temp]==false){
			cout<<temp<<" ";
			visited[temp]=true;
		}
		for(int ptr:adjList[temp]){
			if(visited[ptr]==false)
				S.push(ptr);
		}
	}
}
int main(){
	Graph g(5); 
    g.addEdge(1,0); 
    g.addEdge(0,3); 
    g.addEdge(3,4); 
    g.addEdge(4,0); 
    g.addEdge(0,2);
    g.addEdge(2,1);
  	g.DFS(0);

  	return 0;
}
/*
0 2 1 3 4
*/