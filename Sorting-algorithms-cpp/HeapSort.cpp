#include<iostream>
using namespace std;

void Heapify(int a[],int i,int n){

    int largest = i;

    int l = 2*i+1;
    int r = 2*i+2;
    
    if(l<n && a[largest] < a[l])
        largest = l;

    if(r<n && a[largest] < a[r] )
        largest = r;

    if(largest != i){

        swap(a[largest],a[i]);
        Heapify(a,largest,n);
    }
}

void  HeapSort(int a[], int n){

    for(int i=n-1;i>=0;i--){
        Heapify(a,i,n);
    }

    for(int i = n-1;i>=0;i--){
        swap(a[0],a[i]);
        Heapify(a,0,i);
    }

}    
    
int main(){
    
    int a[] = {2,1,4,5,6,3};

    HeapSort(a,6);    

    for (int i = 0; i < 6; ++i)
    {
        cout<<a[i]<<" ";
    }
}
