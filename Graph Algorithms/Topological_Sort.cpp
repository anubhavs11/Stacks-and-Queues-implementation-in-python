#include<bits/stdc++.h>
using namespace std;

void topological_sort(vector<int> adj[],int n){
    int in_degree[n+1]={0};
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<adj[i].size();j++){
            in_degree[ adj[i][j] ]++;
        }
    }
    bool visited[n+1];
    for(int i=1;i<=n;i++) {
        visited[i] = false;
    }
    
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=1;i<=n;i++){
        if(in_degree[i] == 0){
            q.push(i);
            visited[i] = true;
        }
    }
    
    int T[n],index=0;
    
    while(!q.empty()){
        int v = q.top();
        q.pop();
        
        T[index] = v;
        index++;
        
        for(int i=0;i<adj[v].size();i++){
            if(visited[adj[v][i]] == false){
                
                in_degree[adj[v][i]]--;
                
                if(in_degree[adj[v][i]]==0){
                    q.push(adj[v][i]);
                    visited[adj[v][i]] = true;
                }
                
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<T[i]<<" ";
}

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    
    topological_sort(adj,n);
}
