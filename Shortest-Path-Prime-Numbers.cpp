// Shortest Path to Reach One Prime to Other By Changing Single Digit At a Time
// https://www.geeksforgeeks.org/shortest-path-reach-one-prime-changing-single-digit-time/

#include<bits/stdc++.h>
using namespace std;
#define MX 10001

vector <int> g[MX];
int vis[MX];
int dis[MX];

bool prime[MX];

void primeSeive(){

	memset(prime, true, sizeof(prime));

	prime[0] = false;
	prime[1] = false;

	for(int i=2;i*i<MX;i++){
		if(prime[i]){
			for(int j=i*i;j<MX;j+=i){
				prime[j] = false;
			}
		}
	}
}

// Returns true if u and v Differ by Single Digit. 

bool compare(int u, int v){

	string s1 = to_string(u);
	string s2 = to_string(v);

	int c = 0;

	if(s1[0] != s2[0]) c++;
	if(s1[1] != s2[1]) c++;
	if(s1[2] != s2[2]) c++;
	if(s1[3] != s2[3]) c++;

	return c == 1;
}

void addEdge(int u, int v){

	g[u].push_back(v);
	g[v].push_back(u);
}

int bfs(int u, int v){

	queue <int> q;
	q.push(u);

	vis[u] = 1;

	while(!q.empty()){

		int temp = q.front();
		q.pop();

		for(auto it:g[temp]){
			if(!vis[it]){
				q.push(it);
				vis[it] = 1;
				dis[it] = dis[temp] + 1;
			}
		}
	}
	return dis[v];
}

int main(){

	primeSeive();

	int n1, n2;
	cin>>n1>>n2;

	vector <int> v;

	for(int i=1000;i<=9999;i++){
		if(prime[i])
			v.push_back(i);
	}

	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			if(compare(v[i], v[j]))
				addEdge(i, j);
		}
	}

	int x1, x2;

	for(int i=0;i<v.size();i++){
		if(n1 == v[i]) x1 = i;
		if(n2 == v[i]) x2 = i;
	}

	cout<<bfs(x1, x2);

	return 0;
}