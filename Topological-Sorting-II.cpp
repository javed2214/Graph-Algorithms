// Topological Sorting II
// Lexicographically Smallest TopoLogical Sorting

#include<bits/stdc++.h>
using namespace std;
#define MX 101

vector<int> g[MX];
int in_degree[MX];
vector<int> topo(MX); // Stores Lexicographically Smallest Toposort

bool toposort(int n){	// Returns True if there Exist Toposort, False if there is Cycle

	priority_queue<int,vector<int>,greater<int>> pq;

	for(int i=1;i<=n;i++)
		if(!in_degree[i])
			pq.push(i);

	int ss=1;

	while(!pq.empty()){

		int u=pq.top();
		pq.pop();
		topo[ss++]=u;

		for(auto it:g[u]){
			in_degree[it]--;
			if(!in_degree[it])
				pq.push(it);
		}
	}
	if(topo.size() < n) return false; // Graph Contains Cycle

	return true;
}

int main(){

	int n,e;
	cin>>n>>e;

	for(int i=1;i<=e;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		in_degree[v]++;		// In-Degree of Any Node refers to the Number of Incoming Paths to that Node
	}
	bool x=toposort(n);

	if(x){
		for(int i=1;i<=n;i++)
			cout<<topo[i]<<" ";
	}
	else cout<<"Invalid Graph!";

	return 0;
}