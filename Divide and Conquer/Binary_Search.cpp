#include<iostream>
using namespace std;

int Binary_search(int a[],int start,int end1,int item){
    if(start<end1){
        int mid = start+ (end1-start)/2 ;
         if(a[mid] == item){
            return mid;
         }
         else if(a[mid]>item){
            Binary_search(a,start,mid,item);
         }
         else{
            Binary_search(a,mid+1,end1,item);
         }
    }
    else{
        return -1;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int item;
    cout<<"Enter Item : ";
    cin>>item;
    int flag = Binary_search(a,0,5,item);
    if(flag == -1)
        cout<<"NOT FOUND";
    else
        cout<<"Found at "<<flag;
    return 0;
}
