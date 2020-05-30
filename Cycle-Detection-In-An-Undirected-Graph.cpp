// Cycle Detection in an Undirected Graph
// Using Disjoint Set Union Algorithm
// https://www.youtube.com/watch?v=6K9hdWJn060

#include<bits/stdc++.h>
using namespace std;

#define MAX 10001

int parent[MAX];
int size[MAX];

void init(int n){

    for(int i = 1; i <= n; i++){
        parent[i] = i;
        size[i] = 1;
    }
}

int root(int a){

    while(a != parent[a])
        a = parent[a];
    
    return a;
}

void take_union(int a, int b){

    a = root(a);
    b = root(b);

    if(a != b){

        if(size[b] > size[a])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main(){

    int n, m;
    cin >> n >> m;

    init(n);

    for(int i = 0; i < m; i++){
        
        int a, b;
        cin >> a >> b;

        int x = root(a);
        int y = root(b);

        if(x == y){
            cout << "Contains Cycle";
            return 0;
        }
        else take_union(a, b);
    }

    cout << "Doesn't Contain Cycle";

    return 0;
}