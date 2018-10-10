#include<iostream>
using namespace std;

void Knapsack(int wt[],int val[],int n,int W){
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

int main()
{
	int n;
	cin>>n;
	int W;
	cin>>W;
	int wt[n+1],val[n+1];

	for (int i = 1; i < n+1; ++i)
	{
		cin>>wt[i];
		cin>>val[i];
	}
	Knapsack(wt,val,n,W);
	return 0;
}
