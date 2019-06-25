// Generate List of Possible Words from a Character Matrix
// Given an N*M board, Find List of all Possible Words (Available in the Dictionary) that can be Formed by a Sequence
// of Adjacent/Diagonal Characters on the Board

#include<bits/stdc++.h>
using namespace std;

#define M 3
#define N 4

unordered_set<string> S;
bool vis[M][N];

int row[] = { -1, -1, -1, 0, 1, 0, 1, 1 };
int col[] = { -1, 1, 0, -1, -1, 1, 0, 1 };

bool isValid(int i, int j){

	return (i>=0 and i<M and j>=0 and j<N and !vis[i][j]);
}

void findWords(char mat[M][N], int i, int j, string s){

	vis[i][j]=true;

	s+=mat[i][j];
	S.insert(s);

	for(int p=0;p<8;p++){
		if(isValid(i+row[p],j+col[p]))
			findWords(mat,i+row[p],j+col[p],s);
	}
	vis[i][j]=false;	// BackTracking
}

int main(){

	char mat[M][N]={

		{'M', 'S', 'E', 'F'},
		{'R', 'A', 'T', 'D'},
		{'L', 'O', 'N', 'E'}
	};

	vector<string> words={"START", "NOTE", "SAND", "STONED", "MAN"};

	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			vis[i][j]=false;

	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++)
			findWords(mat,i,j,"");
	}
	for(auto it:words){
		if(S.find(it)!=S.end())
			cout<<it<<"\n";
	}

	return 0;
}