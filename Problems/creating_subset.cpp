
#include<iostream>
#include<math.h>
using namespace std;
 
int main(){
    int a[]={1,3,9,2};
    int n=4;
    
    for(int i=1;i<(1<<n);i++){ 
         for(int j=0;j<n;j++){
             if((i&(1<<j))!=0)
                cout<<a[j]<<" ";
         }
         cout<<endl;
    }
}
