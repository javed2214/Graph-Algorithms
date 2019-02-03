// Shortest Distance and Paths Between Two Vertices using BFS Traversal

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
	void addEdge(int u, int v){

		AdjList[u].push_back(v);
		AdjList[v].push_back(u);
	}
	void printGraph(){

		for(int i=0;i<V;i++){
			cout<<i<<" ";
			for(auto it:AdjList[i])
				cout<<it<<" ";
			cout<<"\n";
		}
	}
	void getPath(int u, int v, int *path, int *dis){

		stack <int> S;
		int x=v;
		while(x!=u){
			S.push(x);
			x=path[x];
		}
		S.push(u);
		while(!S.empty()){
			cout<<S.top()<<"->";
			S.pop();
		}
		cout<<"\nDistance: "<<dis[v]<<"\n";
	}
	void BFSTraversal(int u, int v){

		queue <int> q;
		int path[V];
		memset(path,0,sizeof(path));
		bool visited[V];
		memset(visited,false,sizeof(visited));
		int dis[V];
		memset(dis,0,sizeof(dis));
		q.push(u);
		visited[u]=true;
		while(!q.empty()){

			int temp=q.front();
			q.pop();
			for(auto it:AdjList[temp]){
				if(visited[it]==false){
					visited[it]=true;
					dis[it]=dis[temp]+1;
					path[it]=temp;
					q.push(it);

					if(it==v){
						getPath(u,v,path,dis);
						return;
					}
				}
			}
		}
	}
};
int main(){

	Graph G(10);

	G.addEdge(0,1);
	G.addEdge(0,2);
	G.addEdge(0,3);
	G.addEdge(1,4);
	G.addEdge(1,5);
	G.addEdge(1,9);
	G.addEdge(2,4);
	G.addEdge(2,6);
	G.addEdge(3,5);
	G.addEdge(3,7);
	G.addEdge(4,7);
	G.addEdge(4,8);
	G.addEdge(5,6);
	G.addEdge(7,8);

	int u,v;
	cin>>u>>v;
	G.BFSTraversal(u,v);

	return 0;
}