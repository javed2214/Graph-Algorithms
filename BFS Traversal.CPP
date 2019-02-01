// BFS Traversal of Graph (Level Order Traversal)

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
	void BFS(int root){
		bool *visited=new bool[V+1];
		for(int i=0;i<V;i++)
			visited[i]=false;
		visited[root]=true;
		queue <int> q;
		q.push(root);
		while(!q.empty()){
			int temp=q.front();
			q.pop();
			cout<<temp<<" ";
			for(int ptr:adjList[temp]){
				if(visited[ptr]==false){
					q.push(ptr);
					visited[ptr]=true;
				}
			}
		}
	}
};
int main(){
	Graph G(5);
	G.addEdge(0,1);
	G.addEdge(0,2);
	G.addEdge(1,2);
	G.addEdge(1,3);
	G.addEdge(3,4);
	G.addEdge(4,2);

	G.printAdjList();
	cout<<endl<<"BFS: ";
	G.BFS(0);

	return 0;	
}
/*
OUTPUT ======>>>>

0=>1,2,
1=>0,2,3,
2=>0,1,4,
3=>1,4,
4=>3,2,

BFS: 0 1 2 3 4

*/
