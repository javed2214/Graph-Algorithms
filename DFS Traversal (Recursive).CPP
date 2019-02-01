// DFS Traversal of Graph (Recursive)

#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list <int> *adjList;
public:
	Graph(int v){
		V=v;
		adjList=new list <int> [V];
	}
	void addEdge(int u, int v){
		adjList[u].push_back(v);
		adjList[v].push_back(u);
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
	visited[root]=true;
	cout<<root<<" ";
	for(int ptr:adjList[root]){
		if(visited[ptr]==false)
			DFSUtil(ptr, visited);
	}
}


int main(){
    
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    cout<<endl<<"DFS: ";
    g.DFS(2);

    return 0;	
}

/*
OUTPUT ======>>>>
BFS: 2 0 1 3
*/
