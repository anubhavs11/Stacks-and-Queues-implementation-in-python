    
    # ERROR in code
    
    #include <iostream>
		#include<string.h>

       using namespace std;
       int main()

       {	int CAPACITY = 4;
       		int a[4] = {1,2,4};

       		for (int i = sizeof(a)/sizeof(*a); i < 7; ++i)
       		{	int b;
       			cin>>b;

       			if(i<CAPACITY)
       				a[i] = b;
       			else{
       				int arr[2*CAPACITY];
       				for (int i = 0; i < CAPACITY; ++i)
       				{
       					arr[i] = a[i];
       				}
       				
       				delete[] a;
       				int a[2*CAPACITY];
       				memcpy(a,arr,2*CAPACITY);
       				free(arr);
       				cout<<sizeof(a)/sizeof(*a);
       			}
       		}
       		
           return 0;

       }
