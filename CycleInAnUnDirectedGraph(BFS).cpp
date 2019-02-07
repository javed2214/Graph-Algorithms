// Program to Detect Cycle in an Undirected Unweighted Graph
// Using BFS Algorithm

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>&AdjList, int u, int v){
	AdjList[u].push_back(v);
	AdjList[v].push_back(u);
}

void printGraph(vector<vector<int>>&AdjList, int V){
	for(int i=0;i<V;i++){
		cout<<i<<"=>";
		for(auto it:AdjList[i])
			cout<<it<<" ";
		cout<<"\n";
	}
}

bool isCyclicUtil(vector<vector<int>>&AdjList, int u, bool *visited, int V){
	vector<int>parent(V,-1);
	visited[u]=true;
	queue<int>q;
	q.push(u);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto it:AdjList[x]){
			if(visited[it]==false){
				visited[it]=true;
				q.push(it);
				parent[it]=x;
			}
			else if(parent[x]!=it)
				return true;
		}
	}
	return false;
}

bool isCyclic(vector<vector<int>>&AdjList, int V){

	bool *visited=new bool[V];
	memset(visited,false,sizeof(visited));

	for(int i=0;i<V;i++){
		if(visited[i]==false){
			if(isCyclicUtil(AdjList,i,visited,V))
				return true;
		}
	}
	return false;
}

int main(){

	int V=5;
	vector<vector<int>>AdjList(V);

	addEdge(AdjList,0,1);
	addEdge(AdjList,1,2);
	addEdge(AdjList,2,0);
	addEdge(AdjList,1,3);
	addEdge(AdjList,3,4);

	printGraph(AdjList,V);

	if(isCyclic(AdjList,V)) cout<<"Cycle is Present!";
	else cout<<"Cycle is not Present!";

	return 0;
}
