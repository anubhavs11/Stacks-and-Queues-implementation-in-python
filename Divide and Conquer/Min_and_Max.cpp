#include<iostream>
using namespace std;

int max1=1;
int min1=10;
void min_max(int a[],int start,int end1){
	if(start<end1){
		int mid = start + (end1-start)/2 ;
		min_max(a,start,mid);
		min_max(a,mid+1,end1);
	}
	else{
        if(min1>a[start])
            min1 = a[start];
        if(max1<a[start])
            max1 = a[start];
	}
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
	min_max(a,0,n-1);
	cout<<min1<<" "<<max1<<endl;
}
