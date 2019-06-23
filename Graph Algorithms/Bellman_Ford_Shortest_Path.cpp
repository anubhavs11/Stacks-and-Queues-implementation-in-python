#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    
    vector <int> v [m+1];
    int dis [n+1];

    for(int i = 1; i <=n; i++){
        dis[i] = 2e9;
    }

   for(int i = 0; i < m; i++){
        int s,d,w;
        cin>>s>>d>>w;

        v[i].push_back(s);
        v[i].push_back(d);
        v[i].push_back(w);
   }

    dis[1] = 0;
    for(int i = 0; i < n - 1; i++){
        int j=0;
        while(v[j].size() != 0){

            if(dis[ v[j][0]  ] + v[j][2] < dis[ v[j][1] ] ){
                dis[ v[j][1] ] = dis[ v[j][0]  ] + v[j][2];
            }
            j++;
        }
    }
    for(int i=2;i<=n;i++)
        cout<<dis[i]<<" ";
}
