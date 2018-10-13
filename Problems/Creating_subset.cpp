
#include<iostream>
#include<math.h>
using namespace std;

int binary_conversion(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return (num % 2) + 10 * binary_conversion(num / 2);
    }
}

int main(){
    int a[]={1,3,9,2};
    int n=4,b;
    for(int i=1;i<pow(2,n);i++){ 
         b = binary_conversion(i);
         int j=n-1;
        while(b>0){
            int p = b%10;
            if(p==1)
                cout<<a[j]<<" ";
            j--;
            b = b/10;
        }      
        cout<<endl;
    }
}
