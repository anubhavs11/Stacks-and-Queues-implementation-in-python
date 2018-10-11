#include <iostream>
#include <string.h>
#include<vector>

using namespace std;

void LCS(string x, string y,int m, int n){
    int k[m+1][n+1];

    for (int i = 0; i < m+1; ++i){
        for (int j = 0; j < n+1; ++j){
            if(i==0 || j==0)
                k[i][j] = 0;
            else if(x[i-1] == y[j-1])
                k[i][j] = k[i-1][j-1] + 1;
            else
                k[i][j] = max(k[i-1][j],k[i][j-1]);
        }
    }
    cout<<"LCS size = "<<k[m][n];
    
    int i=m;
    int j=n;
    
    std::vector<char> result ;
    
    while(k[i][j]!=0){
        if(k[i][j]>k[i-1][j] && k[i][j]>k[i][j-1]){
            result.push_back(x[i-1]);
            i--;
            j--;
        }
        else if(k[i][j-1]>k[i-1][j]){
            j--;
        }
        else{
            i--;
        }
    }
    cout<<endl<<"Longest Subsequence : ";
    for(i = result.size()-1;i>=0;i--)
        cout<<result[i];
    
}

int main(){

	string x,y;
    cin>>x;
    cin>>y;
    
    LCS(x,y,x.length(),y.length());
    
    return 0;
}
