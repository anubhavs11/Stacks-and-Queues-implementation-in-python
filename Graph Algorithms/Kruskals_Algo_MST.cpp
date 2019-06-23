#include<bits/stdc++.h>
using namespace std;

int root(int x,int id[]){
    while(x!=id[x]){
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void Union(int x,int y,int id[]){
    int p = root(x,id);
    int q = root(y,id);
    id[p] = id[q];
}

long Kruskals(pair<int,pair<int,int> > adj[], int m,int id[]){
    
    sort(adj,adj+m);
    long cost=0;
    for(int i=0;i<m;i++){
        int w = adj[i].first;
        int x = adj[i].second.first;
        int y = adj[i].second.second;
        if(root(x,id)!=root(y,id)){
            cost += w;
            Union(x,y,id);
        }
    }
    return cost;
}

int main(){
    
    int n,m;
    cin>>n>>m;

    pair<int,pair<int, int>> adj[m];
    for(int i=0;i<m;i++){
        int w;
        int s,d;
        cin>>s;
        cin>>d;
        cin>>w;
        
        adj[i] = make_pair(w,make_pair(s,d));
    }
    
    //Initialization
    int id[n+1];
    for(int i=1;i<=n;i++)
        id[i] = i;
    

    long minimumCost = Kruskals(adj,m,id);
    cout<<minimumCost<<endl;
}
