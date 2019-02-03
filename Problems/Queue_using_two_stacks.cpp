#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s1;
    stack<int> s2;
    int q;
    cin>>q;
    int type,x;
    for(int k=0;k<q;k++){
        cin>>type;
        if(type==1){  // O(1)
            cin>>x; // Enqueue element x into the end of the queue.
            s1.push(x);
        }
        if(type==2){   // O(1) unless stack 2 is empty
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            s2.pop(); //Dequeue the element at the front of the queue.
        }
        if(type==3){   // O(1) unless stack 2 is empty
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            cout<<s2.top()<<endl; //Print the element at the front of the queue.
        }
    }
    return 0;
}

