// Program to Find Shortest Path Between Two Vertices using BFS Traversal

#include<bits/stdc++.h>
using namespace std;

class Graph{

private:
	int V;
	list <int> *AdjList;

public:
	Graph(int V){

		this->V=V;
		AdjList=new list <int> [V];
	}
	void addEdges(int u, int v){

		AdjList[u].push_back(v);
		AdjList[v].push_back(u);
	}
	void printGraph(){

		for(int i=0;i<V;i++){
			cout<<i<<"=>";
			for(auto it:AdjList[i])
				cout<<it<<" ";
			cout<<"\n";
		}
	}
	void printPath(int *path, int u, int v){

		stack <int> S;
		int x=v;
		while(x!=u){
			S.push(x);
			x=path[x];
		}
		S.push(u);
		while(!S.empty()){
			cout<<S.top()<<" ";
			S.pop();
		}
	}
	void shortestPath(int u, int v){

		bool visited[V];
		memset(visited,false,sizeof(visited));
		int path[V];
		memset(path,0,sizeof(path));
		queue <int> q;
		q.push(u);
		visited[u]=true;

		while(!q.empty()){

			int temp=q.front();
			q.pop();
			cout<<temp<<" ";

			for(auto it:AdjList[temp]){
				if(visited[it]==false){
					visited[it]=true;
					path[it]=temp;
					q.push(it);
				}
			}
		}
		cout<<"\nShortest Path: ";
		printPath(path,u,v);
	}
};

int main(){

	Graph G(12);

	G.addEdges(0,1);
	G.addEdges(0,2);
	G.addEdges(0,3);
	G.addEdges(1,4);
	G.addEdges(2,4);
	G.addEdges(3,9);
	G.addEdges(3,10);
	G.addEdges(4,5);
	G.addEdges(5,6);
	G.addEdges(5,2);
	G.addEdges(5,7);
	G.addEdges(6,8);
	G.addEdges(7,8);
	G.addEdges(10,11);

	G.printGraph();
	cout<<"\nBFS: ";
	G.shortestPath(8,2);
	cout<<"\n";

	return 0;
}