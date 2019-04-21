// Program to Find Number of Nodes at any Given Level
// Using BFS

#include<bits/stdc++.h>
using namespace std;

int V=6;
vector<vector<int>> G(V);

void addEdge(int u, int v){

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

int noOfNodes(int lev, int root){

	int level[V+1];
	bool visited[V+1];

	for(int i=0;i<V;i++){
		level[i]=0;
		visited[i]=false;
	}

	queue <int> q;
	q.push(root);
	visited[root]=true;

	while(!q.empty()){

		int temp=q.front();
		q.pop();

		for(auto it:G[temp]){
			if(visited[it]==false){
				level[it]=level[temp]+1;
				visited[it]=true;
				q.push(it);
			}
		}
	}
	int count=0;	
	for(int i=0;i<V;i++){
		if(level[i]==lev)
			count++;
	}
	return count;
}

int main(){

	addEdge(0,1);
	addEdge(0,2);
	addEdge(1,3);
	addEdge(2,4);
	addEdge(2,5);

	printGraph();

	cout<<"No of Nodes at Level 2: ";
	int level=2,root=0;
	cout<<noOfNodes(level,root)<<endl;	

	return 0;
}