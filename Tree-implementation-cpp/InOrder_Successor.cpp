#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

class Tree{
    struct Node *root;
public:
    Tree(){
        root = NULL;
    }
    void insertion(struct Node *r,int value){
        if(value < r->data){
            if(r->left == NULL){
                Node *newNode = new Node;
                newNode->data = value;
                newNode->left = NULL;
                newNode->right = NULL;
                r->left = newNode;
            }
            else{
                insertion(r->left , value);
            }
        }
        else{
            if(r->right == NULL){
                Node *newNode = new Node;
                newNode->data = value;
                newNode->left = NULL;
                newNode->right = NULL;
                r->right = newNode;
            }
            else{
                insertion(r->right , value);
            }
        }
    }
    void insert(int value){
        if(root == NULL){
            Node *newNode = new Node;
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            root = newNode;
        }
        else{
           insertion(root,value);
        }
    }
    int inOrder(struct Node *node,int data,int prev){
        if(node == NULL){
            return prev;
        }
        else{
            prev = inOrder(node->left,data,prev);
            if(prev == data)
                cout<<node->data<<endl;
            prev = node->data;
            prev = inOrder(node->right,data,prev);
            return prev;
        }
    }
    void inOrder_predecessor(int data){
        inOrder(root,data,-1);
    }
};

int main(){
    Tree ob;
    ob.insert(4);
    ob.insert(8);
    ob.insert(20);
    ob.insert(12);
    ob.insert(10);
    ob.insert(14);
    ob.insert(22);
    ob.inOrder_predecessor(12);
}
