/*
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int main(){
	while(true){
		cout << "Shell>";
		string one; 
		getline(cin, one);
		system(one.c_str());
	}
}
*/

#include <stdio.h>
#include <unistd.h>
#define MAXLINE 80 
int main(void)
{
	char *args[MAXLINE/2 + 1];
	int should_run = 1;
	
	while (should_run) {
		printf("osh>");
		fflush(stdout);
	}
}
