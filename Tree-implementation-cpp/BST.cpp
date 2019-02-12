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
    Node* deleteNode(struct Node *r,int data){
        if(data < r->data ){
            r->left = deleteNode(r->left , data);
        }
        else if(data > r->data){
            r->right = deleteNode(r->right , data);
        }
        else{
                if(r->left == NULL && r->right == NULL){
                    delete r;
                    return NULL;
                }
                else if(r->right == NULL){
                    struct Node *temp = r->left;
                    delete r;
                    return temp;
                }
                else if(r->left == NULL){
                    struct Node *temp = r->right;
                    delete r;
                    return temp;
                }
                else{
                    struct Node *temp = getPredecessor(r->left);
                    r->data = temp->data;
                    r->left = deleteNode(r->left , temp->data);
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
            root = deleteNode(root,data);
        }
    }
};

int main(){
    Tree ob;
    ob.insert(10);
    ob.insert(8);
    ob.insert(6);
    ob.insert(12);
    ob.insert(11);
    ob.display();
    cout<<"\n";
    ob.deletion(11);
    ob.display();
}
