
#include <iostream>
#include<stack>

using namespace std;

int main() {
	int a[4][4] = {{1,1,1,0},
	            {0,1,1,0},
	            {1,0,1,1},
	            {0,0,0,1}
	            };
	int visited[] = {0,0,0,0};
	int values[] = {0,1,2,3};
	int n=4;

	stack<int> s;
	s.push(0);
	cout<<values[0]<<endl;
	visited[0]=1;
	int i=0;
	while(!s.empty()){
		int avail=-1;
		for (int j = 0; j < n; ++j){
			if(a[i][j]==1 && visited[j]==0){
				i=j;
				cout<<values[j]<<endl;
				visited[j]=1;
				avail=1;
			} 
		}
		if(avail==-1){
			i = s.top();
			s.pop();
		}
	}

	return 0;
}
