// Word Search Board (InterviewBit)
// https://www.interviewbit.com/problems/word-search-board/
// Famous Graph Problem
// Asked in Amazon, Google and Facebook

#include<bits/stdc++.h>
using namespace std;

bool findWord(int x, int y, int n, int m, int index, vector<string> &v, string str){

	if(index == str.length()) return true;

	if(x<0 or x>=n or y<0 or y>=m) return false;

	if(v[x][y] != str[index]) return false;

	return findWord(x+1,y,n,m,index+1,v,str) or
		   findWord(x-1,y,n,m,index+1,v,str) or
		   findWord(x,y+1,n,m,index+1,v,str) or
		   findWord(x,y-1,n,m,index+1,v,str);
}

int main(){

	cout<<"No of Words: ";
	int x;
	cin>>x;
		
	vector<string> v(x);

	for(int i=0;i<x;i++) cin>>v[i];

	int n=v.size();
	int m=v[0].size();

	string str;
	cin>>str;

	int flag=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i][j]==str[0]){
				bool temp = findWord(i,j,n,m,0,v,str);
				if(temp) flag=1;
			}
		}
	}
	if(flag) cout<<"Word Found!";
	else cout<<"Word Not Found!";

	return 0;
}