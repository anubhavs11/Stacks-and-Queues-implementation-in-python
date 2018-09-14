// Segmentation Fault

#include<iostream>
using namespace std;

void merge(int a[],int start,int mid,int end){

    int n1 = mid-start+1, n2 = end-mid;

    int i,j,k;
    int b[n1],c[n2];

    for(i=0;i<n1;i++)
        b[i] = a[i+start];

    for(i=0;i<n2;i++)
        c[i] = a[i+mid+1];

    i=j=k=0;
    k = start;
    while(i<n1 && j<n2){
        if(b[i]<c[j]){
            a[k] = b[i];
            k++;
            i++;
        }
        else
        {
            a[k] = c[j];
            k++;
            j++;
        }
    }

    while(j<n2)
        a[k++] = c[j++];

    while(i<n1)
        a[k++] = b[i++];
}

void mergeSort(int a[],int start,int end){

    if(start<end){
        int mid = (end + start) / 2;
        mergeSort(a,start,mid);
        mergeSort(a,mid+1,end);

        merge(a,start,mid,end);
    }
}

int main(){
    int a[] = {5,4,6,3,1};
    mergeSort(a,0,5);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
}
