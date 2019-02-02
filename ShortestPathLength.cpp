// Program to Find Minimum Number of Edges between Two Vertices

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

	int BFSTraversal(int u, int v){

		bool visited[V];
		memset(visited,false,sizeof(visited));
		int dis[V];
		memset(dis,0,sizeof(dis));
		visited[u]=true;
		queue <int> Q;
		Q.push(u);

		while(!Q.empty()){
			int temp=Q.front();
			cout<<temp<<" ";
			Q.pop();
			for(auto it:AdjList[temp]){
				if(visited[it]==false){
					visited[it]=true;
					dis[it]=dis[temp]+1;
					Q.push(it);
				}
			}
		}
		cout<<"\nMin No of Edges: ";
		return dis[v];
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
	G.addEdges(5,7);
	G.addEdges(6,8);
	G.addEdges(10,11);

	G.printGraph();
	cout<<"\nBFS: ";
	cout<<G.BFSTraversal(8,11);
	cout<<"\n";

	return 0;
}