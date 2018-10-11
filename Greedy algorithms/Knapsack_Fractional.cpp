#include <iostream>
#include<string.h>
#include <iomanip>

using namespace std;

void SortByRatio(float val[],float w[],int n){

    int p;
    float temp;
    for (int i = 0; i < n; ++i){
        p=i;
        for (int j = i+1; j < n; ++j){
            if(val[p]/w[p] < val[j]/w[j])
                p = j;
        }
        temp = w[p];
        w[p] = w[i];
        w[i] = temp;

        temp = val[p];
        val[p] = val[i];
        val[i] = temp;
        
    }
}

    int main(){

        int t;
        cin>>t;
        while(t>0){
            t--;
            int n;
            float W;
            cin>>n;
            cin>>W;
            float val[n],w[n];

            for (int i = 0; i < n; ++i)
            {
                cin>>val[i]>>w[i];
            }

            SortByRatio(val,w,n);

            float sum=0;
            
            for (int i = 0; i < n; ++i)
            {
                if(W>w[i]){
                    W = W-w[i];
                    sum += val[i];
                }
                else{
                    sum += (W/w[i])*val[i];
                    w[i] = w[i]-W;
                    W=0;
                    break;
                }
            }
             cout<<sum<<endl;
        }
        return 0;
    }
