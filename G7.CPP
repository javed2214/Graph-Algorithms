// Implementation of Weighted Graph

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector <pair <int,int> > *adjList, int, int, int);
void printGraph(vector <pair <int,int> > *adjList, int);

int main(){
	int V=5;
	vector <pair<int, int> > adjList[V];
	addEdge(adjList,0,1,10); 
    addEdge(adjList,0,4,20); 
    addEdge(adjList,1,2,30); 
    addEdge(adjList,1,3,40); 
    addEdge(adjList,1,4,50); 
    addEdge(adjList,2,3,60); 
    addEdge(adjList,3,4,70); 
    printGraph(adjList, V); 
    
    return 0; 
}

void addEdge(vector <pair <int,int> > *adjList, int u, int v, int wt){
	adjList[u].push_back(make_pair(v,wt));
	adjList[v].push_back(make_pair(u,wt));
}
void printGraph(vector <pair <int,int> > *adjList, int V){
	int x,y;
	for(int i=0;i<V;i++){
		cout<<"Node "<<i<<" Makes an Edge With\n";
		for(auto ptr=adjList[i].begin();ptr!=adjList[i].end();ptr++){
			x=ptr->first;
			y=ptr->second;
			cout<<x<<" With Edge Weight="<<y<<endl;
		}
		cout<<endl;
	}
}