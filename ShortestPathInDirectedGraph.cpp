// Program to Find Shortest Path in Directed Graph using BFS

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &AdjList, int u, int v){

	AdjList[u].push_back(v);
}
void printGraph(vector<vector<int>> &AdjList, int V){

	for(int i=0;i<V;i++){
		cout<<i<<"=>";
		for(auto it:AdjList[i])
			cout<<it<<" ";
		cout<<"\n";
	}
}
void getShortestPath(int *path, int src, int dst, int *dis){

	stack <int> S;
	int x=dst;
	while(x!=src){
		S.push(x);
		x=path[x];
	}
	S.push(src);
	while(!S.empty()){
		cout<<S.top()<<" ";
		S.pop();
	}
	cout<<"\nDistance: "<<dis[dst]<<"\n";
	return;
}
void BFSTraversal(vector<vector<int>> &AdjList, int src, int dst, int V){

	queue <int> q;
	q.push(src);
	int visited[V];
	memset(visited,false,sizeof(visited));
	int path[V];
	memset(path,0,sizeof(path));
	int dis[V];
	memset(dis,0,sizeof(dis));
	visited[src]=true;

	while(!q.empty()){

		int temp=q.front();
		q.pop();

		for(auto it:AdjList[temp]){
			if(visited[it]==false){
				visited[it]=true;
				path[it]=temp;
				dis[it]=dis[temp]+1;
				q.push(it);
			}
		}
	}
	getShortestPath(path,src,dst,dis);
	return;
}

int main(){

	int V=9;
	vector<vector<int>> AdjList(V);

	addEdge(AdjList,0,1);	
	addEdge(AdjList,1,4);
	addEdge(AdjList,2,4);
	addEdge(AdjList,2,0);
	addEdge(AdjList,0,3);
	addEdge(AdjList,3,6);
	addEdge(AdjList,6,7);
	addEdge(AdjList,8,6);
	addEdge(AdjList,7,8);
	addEdge(AdjList,7,5);
	addEdge(AdjList,5,2);

	
	printGraph(AdjList,V);

	cout<<"\n";

	int src,dst;
	cin>>src>>dst;

	BFSTraversal(AdjList,src,dst,V);

	return 0;
}