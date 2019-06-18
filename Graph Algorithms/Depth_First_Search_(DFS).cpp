
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
	s.push(2);
	int i;
	while(!s.empty()){
		i = s.top();
		s.pop();
		visited[i] = 1;
		cout<<i<<" ";
		for (int j = 0; j < n; ++j){
		    if(a[i][j]==1 && visited[j]==0){
			s.push(j);
		    } 
		}
	}
	return 0;
}
