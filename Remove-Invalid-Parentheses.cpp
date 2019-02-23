// Remove Invalid Parentheses Problem
// Remove the Minimum Number of Invalid Parentheses in Order to Make the Input String Valid. Return All possible Results.
// Breadth First Search
// https://leetcode.com/problems/remove-invalid-parentheses/

#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string str){

	int c=0;
	for(int i=0;i<str.length();i++){
		if(str[i]=='(') c++;
		else if(str[i]==')') c--;
		if(c<0) return false;
	}
	return c==0;
}

vector<string> removeInvalidParentheses(string str){

	map<string,bool> vis;
	queue<string> q;
	vector<string> vec;
	q.push(str);
	int found=0;
	while(!q.empty()){
		string u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		if(isBalanced(u)){
			found=1;
			vec.push_back(u);
		}
		if(found) continue;
		for(int i=0;i<u.size();i++){
			if(u[i]=='(' or u[i]==')'){
				string v=u.substr(0,i) + u.substr(i+1,u.size());
				q.push(v);
			}
		}
	}
	return vec;
}

int main(){

	string s="()())()";
	vector<string> vec;
	vec=removeInvalidParentheses(s);

	for(auto it:vec) cout<<it<<" ";

	return 0;
}