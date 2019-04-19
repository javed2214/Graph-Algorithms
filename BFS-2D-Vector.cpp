// Shortest Path Using Breadth First Search
// 2D Vector

#include <bits/stdc++.h>
using namespace std;

const int V=12;
vector<vector<int>> G(V);

void addEdges(int u, int v){

	G[u].push_back(v);
	G[v].push_back(u);
}

void printGraph(){

	for(int i=0;i<V;i++){
		cout<<i<<"=>";
		for(auto it:G[i])
			cout<<it<<" ";
		cout<<"\n";
	}
}

void getPath(int *path, int u, int v){

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
}

void BFS(int u, int v){

	bool visited[V+1];
	memset(visited,false,sizeof(visited));

	int path[V+1];

	queue <int> q;
	q.push(u);

	visited[u]=true;

	while(!q.empty()){

		int temp=q.front();
		q.pop();
		cout<<temp<<" ";

		for(auto it:G[temp]){
			if(visited[it]==false){
				q.push(it);
				visited[it]=true;
				path[it]=temp;
			}
		}
	}
	cout<<"\nShortest Path (0,7): ";
	getPath(path,u,v);
}

int main() {

	addEdges(0,1);
	addEdges(0,2);
	addEdges(0,3);
	addEdges(1,4);
	addEdges(2,4);
	addEdges(3,9);
	addEdges(3,10);
	addEdges(4,5);
	addEdges(5,6);
	addEdges(5,2);
	addEdges(5,7);
	addEdges(6,8);
	addEdges(7,8);
	addEdges(10,11);


	printGraph();

	BFS(0,7);

  	
  	return 0;
}