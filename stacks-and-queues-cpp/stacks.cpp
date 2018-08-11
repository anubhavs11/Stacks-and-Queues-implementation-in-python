#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

class stacks{
    struct Node *top;
public:
    stacks(){
        top = NULL;
    }
    void push(int value){
        cout<<"Pushing :"<<value<<endl;
        Node *newNode = new Node;
        newNode->data = value;
        if(top == NULL){
            top = newNode;
            top->next = NULL;
        }
        else{
            newNode->next = top;
            top = newNode;
        }
    }
    void display(){

        Node *t = top;
        if(t == NULL){
            cout<<" No Elements "<<endl;
        }
        else{
            cout<<"Elements: "<<endl;
        }
        while(t!=NULL){
            cout<<t->data<<" ";
            t = t->next;
        }
        cout<<endl;
    }
    void pop(){
        Node *t = top;
        if(top == NULL){
            cout<<"Can't delete , stack empty"<<endl;
            return;
        }
        else if(top->next == NULL){
            top = NULL;
        }
        else{
            while(t->next->next != NULL){
                t = t->next;
            }
            t->next = NULL;
        }
    }
};
int main(){
    stacks ob;
    ob.push(3);
    ob.push(2);
    ob.push(1);
    ob.display();
    ob.pop();
    ob.display();
}
