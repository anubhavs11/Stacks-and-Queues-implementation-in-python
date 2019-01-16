#include<iostream>

using namespace std;


int main(){

    char set[]= "suraj";
    int n=5;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i & (1<<j))
                cout<<set[j];
        }
        cout<<" ";
    }
}
