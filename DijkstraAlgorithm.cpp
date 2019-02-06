// Program to Implement Dijkstra Algorithm
// Applicable for Weighted Graph
// Also called Single Source Shortest Path Algorithm
// No Negative Weights

#include<bits/stdc++.h>
using namespace std;

template <typename T>

class Graph{

private:
	unordered_map<T,list<pair<T,int>>>Map;

public:
	void addEdge(T u, T v, int wt, bool bidr=true){
		Map[u].push_back(make_pair(v,wt));
		if(bidr) Map[v].push_back(make_pair(u,wt));
	}

	void printGraph(){
		for(auto it:Map){
			cout<<it.first<<"=>";
			for(auto ptr:it.second)
				cout<<"("<<ptr.first<<" "<<ptr.second<<") ";
			cout<<"\n";
		}
	}

	void Dijkstra(T src){

		unordered_map<T,int> dist;

		for(auto it:Map)
			dist[it.first]=INT_MAX;

		set<pair<int,T>>Set;
		
		dist[src]=0;
		Set.insert(make_pair(0,src));

		while(!Set.empty()){
			auto p=*(Set.begin());
			
			T node=p.second;
			int nodeDist=p.first;

			Set.erase(Set.begin());

			for(auto it:Map[node]){
				if(nodeDist + it.second < dist[it.first]){
					T dest=it.first;
					auto f=Set.find(make_pair(dist[dest],dest));
					if(f!=Set.end()){
						Set.erase(f);
					}
					dist[dest]=nodeDist + it.second;
					Set.insert(make_pair(dist[dest],dest));
				}
			}
		}
		for(auto d:dist){
			cout<<d.first<<" is Located at a Distance of "<<d.second<<"\n";
		}
	}
};

int main(){

	// Graph<string> G;

	/*
	G.addEdge("Amritsar","Delhi",1);
	G.addEdge("Amritsar","Jaipur",4);
	G.addEdge("Jaipur","Delhi",2);
	G.addEdge("Jaipur","Mumbai",8);
	G.addEdge("Bhopal","Agra",2);
	G.addEdge("Mumbai","Bhopal",3);
	G.addEdge("Agra","Delhi",1);
	*/

	Graph<int> G;

	G.addEdge(1,2,1);
	G.addEdge(1,3,4);
	G.addEdge(1,3,1);
	G.addEdge(3,4,2);
	G.addEdge(1,4,7);

	G.printGraph();

	G.Dijkstra(1);

	return 0;
}