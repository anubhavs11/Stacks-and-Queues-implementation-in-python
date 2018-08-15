#include<iostream>
using namespace std;

template <class T>
struct Node{
T data;
Node<T> *next;
};

template <class T>
class stacks{
    Node<T> *top;
    public:
    stacks(){
        top = NULL;
    }
    void push(T item){
        Node<T> *t1 = top;
        Node<T> *newNode = new Node<T>;
        newNode->data = item;
        newNode->next = NULL;
        if(top == NULL){
            top = newNode;
        }
        else{
            while(t1->next != NULL){
                t1 = t1->next;
            }
            t1->next = newNode;
        }
    }
    void display(){
        Node<T> *t = top;
        while(t != NULL){
            cout<<t->data<<" ";
            t = t->next;
        }
        cout<<endl;
    }
    void deletion(){
        Node<T> *t = top;
        if(top->next == NULL || top == NULL){
            top = NULL;
        }
        else{
            while(t->next != NULL){
                if(t->next->next == NULL){
                    t->next = NULL;
                    break;
                }
                t = t->next;
            }
        }
    }
};

int main(){
    stacks<float> ob;
    ob.push(3);
    ob.push(4);
    ob.push(5.3);
    ob.display();
    ob.deletion();
    ob.display();
    return 0;
}
