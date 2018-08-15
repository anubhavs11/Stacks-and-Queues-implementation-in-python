#include<iostream>
using namespace std;
template <class T>
struct Node{
T data;
Node<T> *next;
};

template <class T>
class Queue{
    Node<T> *front;
    Node<T> *tail;
    public:
        Queue(){
            front = NULL;
            tail = NULL;
        }
        void insertion(T value){
            cout<<"Inserting "<<value<<" \n";
            Node<T> *newNode = new Node<T>;
            newNode->data = value;
            if(front == NULL){
                front=tail=newNode;
                newNode->next = NULL;
            }
            else{
                newNode->next = tail;
                tail = newNode;
            }
        }
        void display(){
            if(tail == NULL){
                cout<<"Queue empty"<<endl;
            }
            else{
                cout<<"Elements:"<<endl;
            }
            Node<T> *f = tail;
            while(f != NULL){
                cout<<f->data<<" ";
                f = f->next;
            }
            cout<<endl;
        }
        void deletion(){
            if(tail == NULL){
                cout<<"Queue already empty"<<endl;
            }
            if(tail->next == NULL){
                cout<<"Deleting"<<endl;
                front = tail = NULL;
            }
            else{
                cout<<"Deleting"<<endl;
                Node<T> *f = tail;
                while(f->next->next != NULL){
                    f = f->next;
                }
                f->next = NULL;
            }
        }
};

int main(){

Queue <int>ob;
ob.insertion(1);
ob.insertion(2);
ob.insertion(3);
ob.display();
ob.deletion();
ob.display();
}

