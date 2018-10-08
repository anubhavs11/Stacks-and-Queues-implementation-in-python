// Choosing last element as pivot

#include<iostream>
using namespace std;

int partition(int a[],int low,int high){
	int pivot = a[high];

	int i=low-1,j;

	for(int j=low;j<high;j++){
		if(a[j]<=pivot){
			i++;
			swap(a[j],a[i]);
		}
	}
	swap(a[i+1],a[high]);
	return i+1;
}

void Quicksort(int a[],int low, int high){
	if(low<high){
		int pi = partition(a,low,high);

		Quicksort(a,low,pi-1);
		Quicksort(a,pi+1,high);
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	Quicksort(a,0,n);
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
}
