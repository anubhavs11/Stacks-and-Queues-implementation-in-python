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
    void deleteNode(struct Node *r,data){
        if(data < r->data ){
            deleteNode(r->left , data);
        }
        else if(data > r->data){
            deleteNode(r->right , data);
        }
        else{
                if(r->left == NULL && r->right == NULL){
                    delete r;
                }
                else if(r->right == NULL){
                    r->data = r->left->data;
                    delete r->left;
                }
                else if(r->left == NULL){
                    r->data = r->right->data;
                    delete r->right;
                }
                else{
                    struct Node *temp = getPredecessor(r->left);
                    r->data = temp->data;
                    deleteNode(r->left , temp->data);
                }
        }
    }
    Node* getPredecessor(struct Node *node){
        if(node->right){
            node->right = getPredecessor(node->right);
        }
        else{
            return node;
        }
    }
    void deletion(int data){
        if(root != NULL){
            deleteNode(root,data);
        }
    }
};

int main(){
    Tree ob;
    ob.insert(1);
    ob.insert(2);
    ob.insert(3);
    ob.insert(4);
    ob.display();
    // Deletion not working
}
