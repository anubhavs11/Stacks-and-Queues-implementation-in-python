#include<iostream>
using namespace std;
int main(){
    int a[]={1,4,1,2,7,5,2};
    
    int m=0,n=sizeof(a)/sizeof(a[0]);
    
    for(int i=0;i<n;i++){
        if(m<a[i])
            m=a[i];
    }
    
    int count[++m];
    
    for(int i=0;i<m;i++)
        count[i]=0;
        
    for(int i=0;i<n;i++)
        count[a[i]]++;
        
    for(int i=1;i<m;i++)
        count[i]+=count[i-1];
        
    int b[n];
    
    // n-1 ->> 0 ::this will make the algorithm become stable i.e. same element will not interchange their position.
    for(int i=n-1;i>=0;i--){
        b[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }
    
    for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
}
