#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Divide(int a[],int n1,int n2,int sum[],int loc){
	if(n1!=n2){
		int mid = n1+(n2-n1)/2;
		sum[loc] = Divide(a,n1,mid,sum,2*loc+1)+Divide(a,mid+1,n2,sum,2*loc+2);
	}
	else{
		sum[loc] = a[n1];
	}
	return sum[loc];
}
int main(){
	int a[]={15,10,9,8,20,16};
	int n=6;
	int sum[2*n+1]={0};
	int root = Divide(a,0,n-1,sum,0);
	for (int i = 0; i <= 2*n; ++i){
		cout<<sum[i]<<" ";
	}
}