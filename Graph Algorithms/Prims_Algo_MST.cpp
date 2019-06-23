#include<bits/stdc++.h>
using namespace std;

long long Prims(vector<pair<long long,int>> adj[],int x,int n){
    long long cost=0;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> Q;
    
    bool marked[n+1];
    for(int i=1;i<=n;i++)
        marked[i] = false;
        
    Q.push(make_pair(0,x));
    
    while(!Q.empty()){
            pair<long long, int > p;

        p = Q.top();
        Q.pop();

        if(marked[p.second] == true)
            continue;
        
        x = p.second;
        cost+=p.first;
        marked[p.second] = true;
        for(int i=0;i<adj[x].size();i++){
            if(marked[ adj[x][i].second ] == false){
                Q.push( make_pair( adj[x][i].first , adj[x][i].second ) );
            }
        }
    }
    
    return cost;
    
}

int main(){
    
    int n,m;
    cin>>n>>m;

    vector<pair<long long,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int w;
        int s,d;
        cin>>s;
        cin>>d;
        cin>>w;
        
        adj[s].push_back(make_pair(w,d));
        adj[d].push_back(make_pair(w,s));
    }
    
    long long minimumCost = Prims(adj,1,n);
    cout<<minimumCost<<endl;
}
