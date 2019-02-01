// Program to Count Number of Possible Paths b/w Two Vertices

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
	int countPath(int s, int d);
	void countPathUtil(int,int,int &,bool *);

};
int Graph:: countPath(int s, int d){
	bool *visited=new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	int pathCount=0;
	countPathUtil(s,d,pathCount,visited);
	return pathCount;
}
void Graph:: countPathUtil(int s,int d,int &pathCount,bool *visited){
	visited[s]=true;
	if(s==d)
		pathCount++;
	else{
		for(int ptr:adjList[s]){
			if(visited[ptr]==false)
				countPathUtil(ptr,d,pathCount,visited);
		}
	}
	visited[s]=false;
}

int main(){
	Graph g(5); 
   	g.addEdge(1,0);
   	g.addEdge(0,2);
   	g.addEdge(1,2);
   	g.addEdge(1,4);
   	g.addEdge(2,4);
   	g.addEdge(3,4);
   	g.addEdge(2,3);
    int s=1,d=4;
    cout<<g.countPath(s,d);

  	return 0;
}
// OUTPUT ==> 5
