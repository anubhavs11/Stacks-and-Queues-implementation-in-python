#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9

int main(){
    int N, M;
    cin>>N>>M;
    
    vector<pair<int, int>> adj[N+1];
    int x1, y, w;
    for(int i = 0; i < M; i++){
        cin>>x1>>y>>w;
        adj[x1].push_back(make_pair(y, w));
    }
    int dis[N+1];
    for(int i = 0; i <= N; i++){
        dis[i] = MAX;
    }
    dis[1] = 0;
    queue<int> q;
    
    q.push(1);
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i = 0; i < adj[x].size(); i++){
            if(dis[adj[x][i].first] > dis[x] + adj[x][i].second){
                dis[adj[x][i].first] = dis[x] + adj[x][i].second;
                q.push(adj[x][i].first);
            }
        }
    }
    for(int i = 2; i <= N; i++){
        cout<<dis[i]<<" ";
        
    }
    cout<<endl;
}
