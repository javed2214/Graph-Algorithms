// Program to Detect Cycle in Directed Graph

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
	return;
}

bool isCyclicUtil(vector<vector<int>> &AdjList, int vx, bool *visited, bool *recStack){
	if(visited[vx]==false){
		visited[vx]=true;
		recStack[vx]=true;

		for(auto it:AdjList[vx]){
			if(visited[it]==false)
				return isCyclicUtil(AdjList,it,V,visited,recStack);
			else if(recStack[it]==true)
				return true;
		}
	}
	recStack[vx]=false;
	return false;
}

bool isCyclic(vector<vector<int>> &AdjList, int V){
	bool *visited=new bool[V];
	bool *recStack=new bool[V];

	for(int i=0;i<V;i++){
		visited[i]=false;
		recStack[i]=false;
	}

	for(int i=0;i<V;i++){
		if(isCyclicUtil(AdjList,i,visited,recStack))
			return true;
	}
	return false;
}

int main(){

	int V=4;
	vector<vector<int>>AdjList(V);

	addEdge(AdjList,0,1);
	addEdge(AdjList,1,2);
	addEdge(AdjList,2,0);
	addEdge(AdjList,0,2);
	addEdge(AdjList,2,3);
	addEdge(AdjList,3,3);

	printGraph(AdjList,V);

	if(isCyclic(AdjList,V)) cout<<"Cycle is Present!";
	else cout<<"Cycle is not Present!";

	return 0;
}
