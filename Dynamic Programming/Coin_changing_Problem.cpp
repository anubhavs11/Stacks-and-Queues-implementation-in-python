
// Coin changing problem

#include<iostream>
#include<vector>

using namespace std;
int main(){

 int n;
 cin>>n;
 int coin[n];
 for(int i=0;i<n;i++)
    cin>>coin[i];

 int sum;
 cin>>sum;
 
 int v[n+1][sum+1];
 
 for(int i=0;i<=sum;i++)
    v[0][i]=i;
 
 for(int i=0;i<=n;i++)
    v[i][0]=0;
 
 for(int i=1;i<=n;i++){
     for(int j=1;j<=sum;j++){
         if(j>coin[i-1]){
             if(j-coin[i]<0){
                 v[i][j] = v[i-1][j];
             }
             else{
                v[i][j] = min(v[i-1][j],v[i][j-coin[i]]+1);    
             }
         }
         else{
             v[i][j] = v[i-1][j];
         }
     }
 }
 
 for(int i=0;i<=n;i++){
     for(int j=0;j<=sum;j++){
        cout<<v[i][j]<<" ";
     }
     cout<<endl;
 }
 
 vector<int> r;
 
 int i=n;
 int j=sum;
 while(j!=0){
    if(v[i][j] == v[i-1][j])
        i=i-1;
    else{
        j = j-coin[i];
        r.push_back(coin[i]); 
    }
 }
 cout<<endl;
 for(int i=0;i<r.size();i++)
    cout<<r[i]<<" ";
}
