// Program to Cout Number of Edges in an Undirected Graph

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
	void printAdjList(){
		for(int i=0;i<V;i++){
			cout<<i<<"=>";
			for(int ptr:adjList[i])
				cout<<ptr<<",";
			cout<<endl;
		}
	}
	int countEdge(){
		int sum=0;
		for(int i=0;i<V;i++)
			sum+=adjList[i].size();
		return sum/2;
	}
};
int main(){
	Graph g(5); 
    g.addEdge(0,1); 
    g.addEdge(0,2);
    g.addEdge(1,2); 
    g.addEdge(1,3); 
    g.addEdge(3,4); 
    g.addEdge(4,2);  
	g.printAdjList();

	int c=g.countEdge();
	cout<<"No of Edges: "<<c;

	return 0;	
}
/*
OUTPUT ======>>>>
0=>1,2,
1=>0,2,3,
2=>0,1,4,
3=>1,4,
4=>3,2,
No of Edges: 6
*/