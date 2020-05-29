// Kruskal's Algorithm for Minimum Spanning Tree
// Based on Greedy Approach
// Implementation Using Disjoint Set Union
// Problem Link: https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/
// Tutorial: https://www.youtube.com/watch?v=XRH1fqAQZrE&list=PL2q4fbVm1Ik64I3VqbVGRfl_OgYzvzt9m&index=3

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000002

struct node{
    int a, b, w;
};

node arr[MAX];
int par[MAX];
int siz[MAX];

bool Comp(node x, node y){
    return x.w < y.w;
}

void init(int n){
    for(int i=0;i<=n;i++) par[i] = i, siz[i] = 1;
}

int find(int a){

    while(a != par[a])
        a = par[a];
    
    return a;
}

void merge(int a, int b){
    if(siz[b] > siz[a]) swap(a, b);
    par[b] = a;
    siz[a] += siz[b];
}

int main(){

    int n, m, a, b, sum = 0;
    cin >> n >> m;

    init(n);

    for(int i=0;i<m;i++) cin >> arr[i].a >> arr[i].b >> arr[i].w;

    sort(arr, arr + m, Comp);

    for(int i=0;i<m;i++){

        a = find(arr[i].a);
        b = find(arr[i].b);

        if(a != b){

            sum += arr[i].w;
            merge(a, b);
        }
    }
    cout << sum << endl;

    return 0;
}
