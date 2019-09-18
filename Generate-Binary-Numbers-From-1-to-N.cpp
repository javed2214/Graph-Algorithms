// Program to Generate Binary Numbers from 1 to N
// https://www.geeksforgeeks.org/interesting-method-generate-binary-numbers-1-n/

#include<bits/stdc++.h>
using namespace std;

void generateNumbers(int n){

	queue <string> q;
	
	q.push("1");

	while(n--){

		string s1 = q.front();
		q.pop();

		cout<<s1<<"\n";

		string s2 = s1;

		q.push(s1 += "0");
		q.push(s2 += "1");
	}
}

int main(){

	int n;
	cin>>n;

	generateNumbers(n);

	return 0;
}