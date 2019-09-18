// Stepping Numbers (Using BFS)
// https://www.geeksforgeeks.org/stepping-numbers/
/*
Given two integers ‘n’ and ‘m’, find all the stepping numbers in range [n, m].
A number is called stepping number if all adjacent digits have an absolute difference of 1.
321 is a Stepping Number while 421 is not.
*/

#include<bits/stdc++.h>
using namespace std;

void bfs(int n, int m, int num){

	queue <int> q;
	q.push(num);

	while(!q.empty()){

		int stepNum = q.front();
		q.pop();

		if(stepNum >= n and stepNum <= m) cout << stepNum << " ";

		if(num == 0 or stepNum > m) continue;

		int lastDigit = stepNum % 10;

		int stepNumA = (stepNum * 10) + (lastDigit - 1);
		int stepNumB = (stepNum * 10) + (lastDigit + 1);

		if(lastDigit == 0) q.push(stepNumB);
		else if(lastDigit == 9) q.push(stepNumA);
		else{
			q.push(stepNumA);
			q.push(stepNumB);
		}
	} 
}

void steppingNumbers(int n, int m){

	for(int i=0;i<=9;i++)
		bfs(n,m,i);
}

int main(){

	int n,m;
	cin>>n>>m;

	steppingNumbers(n,m);

	return 0;
}