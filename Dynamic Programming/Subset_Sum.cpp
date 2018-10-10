#include<iostream>
using namespace std;

int SubsetSum(int a[],int n,int sum){
	int k[n+1][sum+1];

	for (int i = 0; i < n+1; ++i)
		k[i][0] = 1;
	for (int i = 1; i < n+1; ++i)
		k[0][i] = 0;

	for (int i = 1; i < n+1; ++i){
		for (int j = 1; j < sum+1; ++j){
			if(j<a[i-1])
				k[i][j] = k[i-1][j];
			else
				k[i][j] = k[i-1][j] || k[i-1][j-a[i-1]];
		}
	}
	return k[n][sum];
}

int main()
{
	int n;
	cin>>n;
	int sum;
	cin>>sum;
	int a[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	if (SubsetSum(a,n,sum) )
		cout<<"Found the subset sum from the array. \n";
	else
		cout<<"No Subset found \n";
	return 0;
}
