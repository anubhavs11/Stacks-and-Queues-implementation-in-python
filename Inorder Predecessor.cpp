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
    void display(){
        disp(root);
    }
    void disp(struct Node *h){
        if(h == NULL){
            return;
        }
        disp(h->left);
        cout<<h->data<<" ";
        disp(h->right);
    }
    bool inOrder(struct Node *node,int data){
        if(node == NULL){
            return true;
        }
        else{
            inOrder(node->left,data);
            if(node->data == data){
                if(node->right!=NULL){
                    cout<<node->right->data;
                    return false;
                }
                else{
                    return true;
                }
            }
            inOrder(node->right,data);
        }
    }
    void inOrder_predecessor(int data){
        bool flag = inOrder(root,data);
        if(flag)
            cout<<"NOT FOUND";
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
    //ob.display();
    ob.inOrder_predecessor(14);
}
