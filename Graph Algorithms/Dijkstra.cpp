#include<iostream>
using namespace std;
int main(){

	int m;
	cin>>m;

	int adjMatrix[m][m];
	for(int i=0;i<m;i++){
		for (int j = 0; j < m; ++j){
			cin>> adjMatrix[i][j];
		}
	}

	int minPath[m];
	for (int i = 0; i < m; ++i)	{
		minPath[i]=100000;
	}
	minPath[0] = 0; // setting 1st vertex as source

	int visited[m]={0};
	visited[0] = 1;
	int i=0,min,pos;
	while(true){
		for (int j = 0; j < m; ++j){
			if(adjMatrix[i][j]+minPath[i]<minPath[j]){
				minPath[j] = adjMatrix[i][j]+minPath[i];
			}
		}	
		min = 100000;
		for (int j = 0; j < m; ++j){
			if(visited[j]==0 && min>minPath[j]){
				min = minPath[j];
				pos = j;
			}
		} 
		if(min == 100000){
			break;
		}
		else{
			visited[pos]=1;
			i=pos;
		}
	}
	cout<<" Shortest Path from Source:\n";
	for (int i = 0; i < m; ++i){
		cout<<minPath[i]<<" ";
	}
	cout<<endl;
	return 0;
}
/*
Input Sample
0 2 4 100000 100000 100000
100000 0 1 7 100000 100000
100000 100000 0 100000 3 100000
100000 100000 100000 0 100000 1
100000 100000 100000 2 0 5
100000 100000 100000 100000 100000 0
*/