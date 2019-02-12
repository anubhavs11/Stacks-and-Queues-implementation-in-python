// Breadth First Search can also be used for level order traversal of Tree.


#include <iostream>
#include<queue>

using namespace std;

int main() {
	int a[4][4] = {{1,1,1,0},
	            {0,1,1,0},
	            {1,0,1,1},
	            {0,0,0,1}
	            };
	int visited[] = {0,0,0,0};
	int values[] = {0,1,2,3};
	
	queue<int> q;
	q.push(0);
	visited[0] = 1;
	cout<<values[0]<<endl;
	int i=0,n=4;
	
	while(!q.empty()){
	    int avail=-1;
	    for(int j=0;j<n;j++){
	        if(visited[j]==0 && a[i][j]==1){
	            q.push(j);
	            cout<<values[j]<<endl;
	            visited[j]=1;
	            i=j;
	            avail = 1;
	            break;
	        }
	    }
	    if(avail==-1){
	        i = q.front();
	        q.pop();
	    }
	}
	
	return 0;
}
