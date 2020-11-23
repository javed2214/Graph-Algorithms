// Program to Print All Possible Paths from Top Left to Bottom Right of a Matrix

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v){

	for(auto it:v){
		cout<<it<<" ";
	}
	cout<<"\n";
}

void printPaths(int mat[][3], vector<int> v, int i, int j, int n, int m){

	if(i > n || j > m) return;

	v.push_back(mat[i][j]);
	
	if(i==n && j==m){
		printVector(v);
	}

	printPaths(mat,v,i+1,j,n,m);
	printPaths(mat,v,i,j+1,n,m);

	v.pop_back();
}

void printPathUtil(int mat[][3], int n, int m){

	vector<int> v;
	printPaths(mat,v,0,0,n,m);
}

int main(){

	int mat[3][3]={
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	int n=3,m=3;

	printPathUtil(mat,n-1,m-1);

	return 0;
}
