// Graph Implementation Using Adjacency List
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
	void addEdge(int u, int v){		// Bidirectional Edge
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	void printAdjList(){
		for(int i=0;i<V;i++){
			cout<<i<<"=>";
			for(int ptr:adjList[i])
				cout<<ptr<<",";
			cout<<endl;
		}
	}
};
int main(){
	Graph G(4);
	
	G.addEdge(0,1);
	G.addEdge(0,2);
	G.addEdge(0,3);
	G.addEdge(1,3);
	G.addEdge(3,2);

	G.printAdjList();
	
	return 0;	
}
/*
OUTPUT===>>>

0=>1,2,3,
1=>0,3,
2=>0,3,
3=>0,1,2,

*/
