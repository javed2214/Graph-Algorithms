// Program to Find Transpose of a Directed Graph

#include<bits/stdc++.h>
using namespace std;

class Graph{

public:

	void addEdge(vector<int> *AdjList, int u, int v){

		// Directed Graph
		AdjList[u].push_back(v);
	}
	void printGraph(vector<int> *AdjList, int V){

		for(int i;i<V;i++){
			cout<<i<<"=>";
			for(auto it:AdjList[i])
				cout<<it<<" ";
			cout<<"\n";
		}
	}
	void transposeGraph(vector<int> *adj, vector<int> *trans, int V){

		auto it=adj[0];
		int i;
		for(int i=0;i<V;i++){
			for(auto it:adj[i])
				addEdge(trans,it,i);
		}
	}
};
int main(){

	int V=4;

	vector<int> adj[V];
	Graph G;

	G.addEdge(adj,0,1);
	G.addEdge(adj,0,2);
	G.addEdge(adj,1,3);
	G.addEdge(adj,2,3);
	G.addEdge(adj,3,0);
	G.addEdge(adj,2,1);

	G.printGraph(adj,V);
	cout<<"\n";

	vector<int> transpose[V];
	G.transposeGraph(adj,transpose,V);
	G.printGraph(transpose,V);

	return 0;
}