#include<bits/stdc++.h>
#define ll long long
using namespace std;

void dijkastra(vector<pair<ll,ll>> adj[],ll n){
    
    bool visited[n+1];
    ll dis[n+1];
    for(ll i=1;i<=n;i++){
        visited[i] = false;
        dis[i] = 1e9;
    }
    dis[1] = 0;
    
    multiset<pair<ll,ll> > ms;
    
    ms.insert(make_pair(0,1));
    
    while(!ms.empty()){
        pair<ll,ll> p = *ms.begin();
        ms.erase(ms.begin());
        
        if(visited[p.second])
            continue;
            
        visited[p.second] = true;
        ll x = p.second;
        
        for(ll i=0;i<adj[x].size();i++){
            ll d = adj[x][i].second;
            ll w = adj[x][i].first;
            if( dis[d] > dis[x] + w ){
                dis[d] = dis[x] + w ;
                ms.insert(make_pair(dis[d],d));
            }
        }
    }
    
    for(ll i=2;i<=n;i++)
        cout<<dis[i]<<" ";
}

int main(){
    ll n,m;
    cin>>n>>m;
    
    vector<pair<ll,ll>> adj[n+1];
    
    for(ll i=0;i<m;i++){
        long long s,d,w;
        cin>>s>>d>>w;
        
        adj[s].push_back(make_pair(w,d));
    }
    
    dijkastra(adj,n);
}
