// Program to Implement Undirected Weighted Graph Using Vector of Pair Vectors

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> *AdjList, int u, int v, int wt){

	AdjList[u].push_back(make_pair(v,wt));
	AdjList[v].push_back(make_pair(u,wt));
}
void printGraph(vector<pair<int,int>> *AdjList, int V){

	for(int i=0;i<V;i++){
		cout<<"Node "<<i<<" Makes an Edge With\n";
		for(auto it:AdjList[i])
			cout<<"\tNode "<<it.first<<" with Edge Weight: "<<it.second<<"\n";
		cout<<"\n";
	}
}


int main(){

	int V=4;
	vector<pair<int,int>> AdjList[V];

	addEdge(AdjList,0,1,10);
	addEdge(AdjList,0,2,3);
	addEdge(AdjList,0,3,2);
	addEdge(AdjList,2,3,6);
	addEdge(AdjList,1,3,7);

	printGraph(AdjList,V);

	return 0;
}