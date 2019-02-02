// Program to Find the Path from Node to Root/Ancestors Using BFS Traversal

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

	void getPath(int *path, int u, int v, int root){

		stack <int> S;
		int x=v;
		while(x!=u and x!=root){
			S.push(x);
			x=path[x];
		}
		S.push(u);
		
		while(!S.empty()){
			cout<<S.top()<<"->";
			S.pop();
		}
		cout<<"\n";
	}

	void BFSTraversal(int root, int u, int v){

		bool visited[V];
		memset(visited,false,sizeof(visited));
		int path[V];
		memset(path,0,sizeof(path));
		queue <int> Q;
		Q.push(root);
		visited[root]=true;
		while(!Q.empty()){

			int temp=Q.front();
			cout<<temp<<" ";
			Q.pop();

			for(int it:AdjList[temp]){
				if(visited[it]==false){
					visited[it]=true;
					path[it]=temp;
					Q.push(it);
				}
			}
		}
		cout<<"\nPath: ";
		getPath(path,u,v,root);
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
	G.addEdges(7,8);
	G.addEdges(10,11);

	G.printGraph();
	cout<<"\nBFS: ";
	G.BFSTraversal(0,11,8);

	return 0;
}