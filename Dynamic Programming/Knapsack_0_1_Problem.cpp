#include <iostream>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t>0){
	    t--;
	    int n;
	    cin>>n;
	    int W;
	    cin>>W;
	    int val[n+1],wt[n+1];
	    for(int i=0;i<n;i++)
	        cin>>val[i];
	    for(int i=0;i<n;i++)
	        cin>>wt[i];
	        
	    int k[n+1][W+1];

        for (int i = 0; i < n+1; ++i){
        	for (int w = 0; w < W+1; ++w)
        	{
        		if(i==0 || w==0)
        			k[i][w] = 0;
        
        		else if(w >= wt[i-1]){
        			if(w-wt[i-1]>=0)
        				k[i][w] = max(k[i-1][w],val[i-1]+k[i-1][w-wt[i-1]]);
        			else
        				k[i][w] = k[i-1][w];
        		}
        		else{
        			k[i][w] = k[i-1][w];
        		}
        	}
        }
        cout<<k[n][W]<<endl;
	}
	return 0;
}
