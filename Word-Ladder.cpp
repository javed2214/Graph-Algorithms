// Word Ladder (Length of Shortest Chain to reach a Target Node)
// https://www.geeksforgeeks.org/word-ladder-length-of-shortest-chain-to-reach-a-target-word/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	string word;
	int len;
};

int isAdjacent(string s1, string s2){

	int co = 0;

	for(int i=0;i<s1.length();i++){
		if(s1[i] != s2[i]) co++;
		if(co > 1) return 0;
	}
	return 1;
}

int shortestLength(string src, string dest, set <string> &S){

	queue <node> q;
	node item;

	item.word = src;
	item.len = 1;

	q.push(item);

	while(!q.empty()){

		node curr = q.front();
		q.pop();

		for(auto it:S){
			if(isAdjacent(it,curr.word)){
				item.word = it;
				item.len = curr.len + 1;
				q.push(item);
				S.erase(it);

				if(it == dest) return item.len;
			}
		}
	}
	return -1;
}

int main(){

	set <string> S = {
		"POON", "PLEE", "SAME", "POIE", "PLIE", "POIN", "PLEA"
	};

	string src = "TOON";
	string dest = "PLEA";

	cout << shortestLength(src,dest,S);

	return 0;
}