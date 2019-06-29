// Bellman Ford Algorithm

#include<bits/stdc++.h>
using namespace std;

struct edge{
	
	int src;
	int dest;
	int wt;
};

void bellmanFord(vector<edge> &g, int source, int n){

	int e = g.size();

	vector<int> dis(n,INT_MAX);
	dis[source] = 0;

	int u,v,w;

	for(int i=0;i<n;i++){
		
		for(int j=0;j<e;j++){
			
			u=g[j].src;
			v=g[j].dest;
			w=g[j].wt;

			if(dis[v] > dis[u] + w and dis[u] != INT_MAX)
				dis[v] = dis[u] + w;
		}
	}

	// Run a relaxation step once more for nth time
	// to check for negative weight cycle

	for(int i=0;i<e;i++){

		u=g[i].src;
		v=g[i].dest;
		w=g[i].wt;

		if(dis[v] > dis[u] + w and dis[u] != INT_MAX){
			cout<<"Graph contains Negative Weight Cycle";
			return;
		}
	}
	for(int i=0;i<n;i++){
		cout<<"Distance of Vertex "<<i<<" from Source 0 is "<<dis[i];
		cout<<"\n";
	}
}

int main(){

	vector<edge> g = {
		{ 0, 1, -1 }, { 0, 2, 4 }, { 1, 2, 3 }, { 1, 3, 2 },
		{ 1, 4, 2 }, { 3, 2, 5 }, { 3, 1, 1 }, { 4, 3, -3 }
	};

	int n=5;
	int source=0;

	bellmanFord(g,source,n);

	return 0;
}